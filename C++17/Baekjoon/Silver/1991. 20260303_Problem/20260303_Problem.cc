#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    char left;
    char right;
};

Node tree[26];

void preorder(char current)
{
    if (current == '.') return;
    cout << current;
    preorder(tree[current - 'A'].left);
    preorder(tree[current - 'A'].right);
}

void inorder(char current)
{
    if (current == '.') return;
    inorder(tree[current - 'A'].left);
    cout << current;
    inorder(tree[current - 'A'].right);
}

void postorder(char current)
{
    if (current == '.') return;
    postorder(tree[current - 'A'].left);
    postorder(tree[current - 'A'].right);
    cout << current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        char root, l, r;
        cin >> root >> l >> r;
        tree[root - 'A'].left = l;
        tree[root - 'A'].right = r;
    }

    preorder('A'); cout << "\n";
    inorder('A'); cout << "\n";
    postorder('A'); cout << "\n";

    return 0;
}