#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int BFS(vector<int> adj[], int start, int V, vector<int> destinations, int m)
{
    int *distance = new int[V]; // tablica odległości
    bool visited[V];            // tablica odwiedzonych wierzchołków
    int max = 0;                // zmienna przechowująca maksymalną odległość

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    queue<int> q; // kolejka do przechowywania wierzchołków - jest to kolejka FIFO
    q.push(start);
    distance[start] = 0;
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();

        for (int v : adj[node])
        {
            if (!visited[v])
            {
                distance[v] = distance[node] + 1;

                for (int dest : destinations)
                {
                    if (v == dest)
                    {
                        if (distance[v] > max)
                        {
                            max = distance[v];
                        }
                    }
                }
                q.push(v);
                visited[v] = true;
            }
        }
        q.pop();
    }

    return max;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;    // liczba wszystkich wiosek
    int m;    // liczba wiosek odwiedzanych przez Kazimierza
    string s; // nazwa wioski

    cin >> n >> m;

    vector<int> adj[n];    // lista sąsiedztwa - tablica list
    map<string, int> mapa; // nazwa wioski - klucz, numer wioski

    for (int i = 0; i < n; i++) // wczytujemy wioski
    {
        cin >> s;
        mapa.insert(pair<string, int>(s, i)); // dodajemy do mapy nazwę wioski i jej numer
    }

    int counter = 0; // licznik wiosek

    while (counter < n)
    {
        cin >> s;

        if (s == "X")
        {
            counter++;
        }
        else
        {
            addEdge(adj, counter, mapa[s]);
        }
    }

    cin >> s; // wioska startowa

    int start = mapa[s];  // numer wioski startowej
    vector<int> villages; // lista wiosek odwiedzanych przez Kazimierza

    string end_village; // nazwa wioski końcowej

    for (int i = 0; i < m; i++)
    {
        cin >> end_village;
        villages.push_back(mapa[end_village]);
    }

    int max = 0; // maksymalna odległość

    max = BFS(adj, start, n, villages, m);

    cout << max;

    return 0;
}

// został użyty tutaj graf nieskierowany co oznacza, że że można przejść z wierzchołka u do wierzchołka v i z powrotem. W przypadku grafu skierowanego krawędzie miałyby jedynie jednokierunkowe połączenie.

// czas wykonania dodawania krawędzi do listy sąsiedztwa to O(1) ponieważ jest to tablica list
// czas wykonania BFS to O(V+E) gdzie V to liczba wierzchołków a E to liczba krawędzi
