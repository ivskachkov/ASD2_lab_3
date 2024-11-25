#include "table.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>

Table::Table(): root(new Node), count(1) {}

Value Table::search(int v) {
    for (const auto& record : records) {
        if (record.first == v && !record.isRemoved) {
            return record;
        }
    }
    return {0, "", false};

}

void Table::edit(int v, const string &s, int & iteration)
{
    auto &k = ::search(root, v, iteration);
    if(k.first == 0)
        return;
    k.second = s;
}

void Table::insert(const string &s)
{
    records.push_back({count, s, false});
    ::insert(root, count++, s);
}

bool Table::remove(int v) {
    for (auto& record : records) {
        if (record.first == v) {
            record.isRemoved = true;
            return true;
        }
    }
    return false;
}

void Table::SaveToFile(const string &file_name)
{
    while(true){
        std::ofstream file(file_name, std::ios::out | std::ios::trunc);

        if (!file.is_open()) {
            std::ofstream newfile(file_name);
            newfile.close();
            continue;
        }

        for (const auto &record : records) {
            std::ostringstream line;

            line << (record.isRemoved ? '1' : '0') << ":";

            std::ostringstream index_stream;
            index_stream << std::setw(5) << std::setfill('_') << record.first;
            line << index_stream.str() << ":";

            std::string adjusted_string = record.second;
            if (adjusted_string.length() > 15) {
                adjusted_string = adjusted_string.substr(0, 15);
            }
            line << std::setw(15) << std::setfill('_') << adjusted_string;

            if (line.str().length() != 23) {
                throw std::runtime_error("Формат запису порушено: запис перевищує 23 символи.");
            }

            file << line.str() << "\n";
        }

        file.close();
        break;
    }
}

void Table::LoadFromFile(const string &file_name)
{
    std::ifstream file(file_name, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Неможливо відкрити файл для читання: " + file_name);
    }

    records.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.length() != 23) {
            throw std::runtime_error("Формат запису порушено: рядок не відповідає 23 символам.");
        }

        char is_removed_char = line[0];
        if (is_removed_char != '0' && is_removed_char != '1') {
            throw std::runtime_error("Неправильний формат isRemoved у записі.");
        }
        bool is_removed = (is_removed_char == '1');

        std::string index_str = line.substr(2, 5);
        index_str.erase(std::remove(index_str.begin(), index_str.end(), '_'), index_str.end());
        int index = std::stoi(index_str);

        std::string adjusted_string = line.substr(8, 15);
        adjusted_string.erase(std::remove(adjusted_string.begin(), adjusted_string.end(), '_'), adjusted_string.end());

        records.push_back({index, adjusted_string, is_removed});
    }

    file.close();
}
