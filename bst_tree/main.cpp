#include <iostream>
using namespace std;

struct Faktura
{
    string name;
    unsigned int counter; // licznik wystąpień
};

struct node
{
    Faktura data;
    node *left;  // wskaźnik na lewe dziecko
    node *right; // wskaźnik na prawe dziecko
};

node *createNode(string data);

void insert(node *root, string data);

void printInOrder(node *root);

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned int n; // liczba faktur
    string name;    // nazwa faktury
    cin >> n;
    cin >> name;

    node *root = createNode(name); // tworzymy korzeń drzewa aby móc go przekazać do funkcji insert i miec jakiekolwiek odniesienie

    while (n > 1) // wczytujemy pozostałe faktury
    {
        cin >> name;
        insert(root, name); // wstawiamy fakturę do drzewa
        n--;
    }

    printInOrder(root); // wypisujemy faktury w kolejności alfabetycznej

    return 0;
}

node *createNode(string data)
{
    node *newNode = new node;
    newNode->data.name = data;
    newNode->data.counter = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node *root, string data) // wstawiamy fakturę do drzewa
{
    if (data < root->data.name)
    {
        if (root->left == NULL)
        {
            root->left = createNode(data);
        }
        else
        {
            insert(root->left, data);
        }
    }
    else
    {
        if (data == root->data.name) // jeśli nazwa faktury jest równa nazwie węzła to zwiększamy licznik wystąpień
        {
            root->data.counter++;
            return;
        }
        else // jeśli nazwa faktury jest większa od nazwy węzła to idziemy w prawo
        {
            if (root->right == NULL)
            {
                root->right = createNode(data);
            }
            else
            {
                insert(root->right, data);
            }
        }
    }
}

void printInOrder(node *root)
{
    if (root->left != NULL) // jeśli istnieje lewe dziecko to idziemy w lewo
        printInOrder(root->left);
    for (int i = 0; i < root->data.counter; ++i)
        cout << root->data.name << '\n'; // wypisujemy nazwę faktury tyle razy ile jest w liczniku wystąpień oraz wracamy do naszego korzenia
    if (root->right != NULL)             // jeśli istnieje prawe dziecko to idziemy w prawo
        printInOrder(root->right);
}
