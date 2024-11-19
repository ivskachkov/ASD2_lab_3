#ifndef DB_H
#define DB_H

#include <vector>
#include <algorithm>
#include <map>

using namespace std;
constexpr int T = 100;

struct Node
{
    vector<Node*> children;
    vector<pair<int, string>> value;
    bool leaf;
    Node(bool isLeaf) : leaf(isLeaf) {}
};

bool isLeaf(Node *node){
    return node->leaf;
}

int binarySearch(const vector<pair<int, string>>& values, int k) {
    int left = 0;
    int right = values.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (values[mid].first == k)
            return mid;
        else if (values[mid].first < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

pair<int, string>& search(Node *node, int v) {
    int i = binarySearch(node->value, v);

    if (i < node->value.size() && node->value[i].first == v)
        return node->value[i];

    if (!node->leaf && i < node->children.size())
        return search(node->children[i], v);

    static pair<int, string> a = {0, ""};
    return a;
}

bool remove(Node*& root, Node*& node, int k) {
    int i = binarySearch(node->value, k);

    if (i < node->value.size() && node->value[i].first == k) {
        if (isLeaf(node)) {
            node->value.erase(node->value.begin() + i);
            return true;
        } else {
            if (node->children[i]->value.size() >= T) {
                Node* predecessorNode = node->children[i];
                while (!isLeaf(predecessorNode)) {
                    predecessorNode = predecessorNode->children.back();
                }
                int predecessorValue = predecessorNode->value.back().first;
                node->value[i].first = predecessorValue;
                return remove(root, node->children[i], predecessorValue);
            } else if (node->children[i + 1]->value.size() >= T) {
                Node* successorNode = node->children[i + 1];
                while (!isLeaf(successorNode)) {
                    successorNode = successorNode->children.front();
                }
                int successorValue = successorNode->value.front().first;
                node->value[i].first = successorValue;
                return remove(root, node->children[i + 1], successorValue);
            } else {
                Node* leftChild = node->children[i];
                Node* rightChild = node->children[i + 1];

                leftChild->value.push_back(node->value[i]);
                leftChild->value.insert(leftChild->value.end(), rightChild->value.begin(), rightChild->value.end());
                leftChild->children.insert(leftChild->children.end(), rightChild->children.begin(), rightChild->children.end());

                delete rightChild;
                node->value.erase(node->value.begin() + i);
                node->children.erase(node->children.begin() + i + 1);

                if (node->value.empty() && node == root) {
                    delete root;
                    root = leftChild;
                }

                return remove(root, leftChild, k);
            }
        }
    }

    if (isLeaf(node)) {
        return false;
    }

    bool shouldBalance = (node->children[i]->value.size() < T);

    if (shouldBalance) {
        if (i > 0 && node->children[i - 1]->value.size() >= T) {
            Node* leftSibling = node->children[i - 1];
            Node* currentChild = node->children[i];

            currentChild->value.insert(currentChild->value.begin(), node->value[i - 1]);
            node->value[i - 1] = leftSibling->value.back();
            leftSibling->value.pop_back();

            if (!isLeaf(leftSibling)) {
                currentChild->children.insert(currentChild->children.begin(), leftSibling->children.back());
                leftSibling->children.pop_back();
            }
        } else if (i < node->children.size() - 1 && node->children[i + 1]->value.size() >= T) {
            Node* rightSibling = node->children[i + 1];
            Node* currentChild = node->children[i];

            currentChild->value.push_back(node->value[i]);
            node->value[i] = rightSibling->value.front();
            rightSibling->value.erase(rightSibling->value.begin());

            if (!isLeaf(rightSibling)) {
                currentChild->children.push_back(rightSibling->children.front());
                rightSibling->children.erase(rightSibling->children.begin());
            }
        } else {
            if (i < node->children.size() - 1) {
                Node* leftChild = node->children[i];
                Node* rightChild = node->children[i + 1];

                leftChild->value.push_back(node->value[i]);
                leftChild->value.insert(leftChild->value.end(), rightChild->value.begin(), rightChild->value.end());
                leftChild->children.insert(leftChild->children.end(), rightChild->children.begin(), rightChild->children.end());

                delete rightChild;
                node->value.erase(node->value.begin() + i);
                node->children.erase(node->children.begin() + i + 1);
            } else {
                Node* leftChild = node->children[i - 1];
                Node* rightChild = node->children[i];

                leftChild->value.push_back(node->value[i - 1]);
                leftChild->value.insert(leftChild->value.end(), rightChild->value.begin(), rightChild->value.end());
                leftChild->children.insert(leftChild->children.end(), rightChild->children.begin(), rightChild->children.end());

                delete rightChild;
                node->value.erase(node->value.begin() + i - 1);
                node->children.erase(node->children.begin() + i);
            }
        }
    }

    return remove(root, node->children[i], k);
}

void splitChild(Node* parent, int i) {
    Node* fullChild = parent->children[i];
    Node* newChild = new Node(fullChild->leaf);

    for (int j = 0; j < T - 1; j++) {
        newChild->value.push_back(fullChild->value[j + T]);
    }

    if (!isLeaf(fullChild)) {
        for (int j = 0; j < T; j++) {
            newChild->children.push_back(fullChild->children[j + T]);
        }
    }

    fullChild->value.resize(T - 1);

    parent->children.insert(parent->children.begin() + i + 1, newChild);
    parent->value.insert(parent->value.begin() + i, fullChild->value[T - 1]);
}

void insertNonFull(Node* node, int k) {
    int i = binarySearch(node->value, k);
    //TODO: make_pair(k, !!!!! - запис)
    if (isLeaf(node)) {
        node->value.insert(node->value.begin() + i, make_pair(k, ""));
    } else {
        if (node->children[i]->value.size() == 2 * T - 1) {
            splitChild(node, i);
            if (k > node->value[i].first) {
                i++;
            }
        }
        insertNonFull(node->children[i], k);
    }
}

void insert(Node*& root, int k) {
    if (root->value.size() == 2 * T - 1) {
        Node* newRoot = new Node(false);
        newRoot->children.push_back(root);
        splitChild(newRoot, 0);
        insertNonFull(newRoot, k);
        root = newRoot;
    } else {
        insertNonFull(root, k);
    }
}

#endif // DB_H