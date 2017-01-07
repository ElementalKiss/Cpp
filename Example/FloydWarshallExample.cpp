#include <iostream>
#include <vector>
#include <stack>

using Elems = std::vector<int>;
using CostTable = std::vector<Elems>;
using ViaTable = std::vector<Elems>;
using PathTable = std::vector<Elems>;

const int VERTEX = 4;
const int INF = 0xFFFFFF;
const int NIL = -0xFFFFFF;

void PrintTable(const std::vector<Elems>&);
void PrintPath(const PathTable&);
void DoFloyd(const ViaTable&, CostTable&, PathTable&);

int main()
{
    ViaTable viaTable;
    viaTable.reserve(VERTEX);
    viaTable.push_back(Elems({ 0,3,INF,INF }));
    viaTable.push_back(Elems({ INF,0,12,6 }));
    viaTable.push_back(Elems({ INF,5,0,7 }));
    viaTable.push_back(Elems({ 2,9,4,0 }));

    PrintTable(viaTable);

    CostTable costTable = viaTable;

    PathTable pathTable;
    pathTable.reserve(VERTEX);
    pathTable.push_back(Elems({ NIL,0,NIL,3 }));
    pathTable.push_back(Elems({ 0,NIL,1,1 }));
    pathTable.push_back(Elems({ NIL,2,NIL,2 }));
    pathTable.push_back(Elems({ 3,3,3,NIL }));

    DoFloyd(viaTable, costTable, pathTable);

    PrintTable(costTable);
    PrintTable(pathTable);
    PrintPath(pathTable);

    return 0;
}

void PrintTable(const std::vector<Elems>& someTable)
{
    for (auto& elems : someTable)
    {
        for (auto& elem : elems)
        {
            if (elem == INF)
            {
                std::cout << "f\t";
            }
            else if (elem == NIL)
            {
                std::cout << "n\t";
            }
            else
            {
                std::cout << elem << "\t";
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void PrintPath(const PathTable& path)
{
    for (size_t i = 0; i < VERTEX; i++)
    {
        for (size_t j = 0; j < VERTEX; j++)
        {
            if (path[i][j] == NIL)
            {
                continue;
            }

            int prev = j;
            std::stack<int> temp;

            temp.push(prev);

            while (i != path[i][prev])
            {
                if (prev == path[i][prev])
                {
                    break;
                }

                prev = path[i][prev];
                temp.push(prev);
            }

            std::cout << i << " to " << j << " path = " << i;

            while (!temp.empty())
            {
                std::cout << "->" << temp.top();
                temp.pop();
            }

            std::cout << std::endl;
        }
    }
}

void DoFloyd(const ViaTable& via, CostTable& cost, PathTable& path)
{
    for (size_t k = 0; k < VERTEX; k++)
    {
        for (size_t i = 0; i < VERTEX; i++)
        {
            for (size_t j = 0; j < VERTEX; j++)
            {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}