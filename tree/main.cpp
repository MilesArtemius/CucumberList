#include "binary_search_tree.hpp"

int main() {
    // создание пустого дерева
    BinarySearchTree <int> intTree;
// добавление узлов
    intTree.put(10);
    intTree.put(3);
    intTree.put(20);
    intTree.put(15);
    intTree.add(30);
    intTree.add(2);
    intTree.add(5);
    intTree.add(32);
    intTree.add(22);
// Вывод узлов дерева в выходной поток
    intTree.out(cout);
// Поиск в дереве по ключу
    bool keyFound = intTree.has(15); // поиск должен быть успешным
    cout << "Key " << 15 << (keyFound ? " found successfully" : " not found") << " in the tree" << endl;
    keyFound = intTree.has(23); // поиск должен быть неудачным
    cout << "Key " << 23 << (keyFound ? " found successfully" : " not found") << " in the tree" << endl;
// определение высоты и количества узлов дерева
    cout << "height = " << intTree.height() << endl;
    cout << "count = " << intTree.count () << endl;
// . . .
    return 0;
}

