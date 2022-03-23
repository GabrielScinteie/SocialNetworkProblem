/*
 Fisierul de input va avea pe prima linie numarul de useri de pe reteaua de socializare
 Pe urmatoarea linie se va introducere perechea (A, B) pentru care vom cauta drumul cel mai scurt
 Pe urmatoarele linii vor fi perechi (a,b) cu insemnatatea ca a este prieten cu b.

 Vom modela prietenii ca fiind noduri intr-un graf neorientat, muchiile fiind formate de relatiile de prietenie de lungime 1
 Vom folosi o lista de adiacenta pentru reprezentarea grafului
*/

#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map<int, bool> visited;
vector<int>* adjacencyList;

int minimalChain(vector<int>*& adjacencyList, int usersNumber, int A, int B);
void dfs(vector<int>*& adjacencyList, int node, int depth, int& minimalChainLength, int B);


int main()
{
    int usersNumber, A, B, x, y;


    fin >> usersNumber;
    fin >> A >> B;

    adjacencyList = new vector<int>[usersNumber + 1];

    while(fin >> x >> y)
    {
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    if(minimalChain(adjacencyList, usersNumber, A, B) == -1)
        fout << "Nu exista nici o secventa de useri care sa lege pe utilizatorii " << A << " si " << B;
    else
        fout << minimalChain(adjacencyList, usersNumber, A, B);

    return 0;
}

int minimalChain(vector<int>*& adjacencyList, int usersNumber, int A, int B)
{
    int minimumLength = usersNumber;
    dfs(adjacencyList, A, 0, minimumLength, B);
    if(minimumLength == usersNumber)
        return -1;
    return minimumLength;
}

void dfs(vector<int>*& adjacencyList, int node, int depth, int& minimalChainLength, int B)
{
    if(depth > minimalChainLength)
        return;

    if(depth < minimalChainLength  && node == B)
        minimalChainLength = depth;

    visited[node] = true;
    for(int i = 0; i < adjacencyList[node].size(); i++)
        if(visited[adjacencyList[node][i]] == false)
            dfs(adjacencyList, adjacencyList[node][i], depth + 1, minimalChainLength, B);

    visited[node] = false;
}
