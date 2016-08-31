#include "iostream"
#include "vector"
#include "stack"
#include "fstream"

using namespace std;

std::vector<vector<int> > weight;
std::vector<vector<int> > path;
int vertexnum;
int edgenum;
const int intmax = 10000;

void initialvector()
{
    weight.resize(vertexnum);//路径权重数组
    path.resize(vertexnum);//保存最短路径数组,记录前继
    for (int i = 0;i < vertexnum;i++) {//建立数组
        weight[i].resize(vertexnum,intmax);
        path[i].resize(vertexnum,-1);
    }
}

//获取数据
void getData() 
{   
    ifstream in("data");
    in >> vertexnum >> edgenum;
    initialvector();
    int from,to;
    double w;
    while (in >> from >> to>> w) {
        weight[from][to] = w;
        path[from][to] = from;//to的前继是from
        weight[from][from] = 0;//自身到自身的权重为0
        path[from][from] = from;
        weight[to][to] = 0;
        path[to][to] = to;
    }
}

void floyd()
{
    for (int k = 0;k < vertexnum;k++) {
        for (int i= 0;i < vertexnum;i++) {
            for (int j = 0;j < vertexnum;j++){
                if((weight[i][k] > 0 && weight[k][j] && weight[i][k] < intmax && weight[k][j] < intmax) 
                && (weight[i][k] + weight[k][j] < weight[i][j])) {//前面一部分是防止加法溢出
                    weight[i][j] = weight[i][k] + weight[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

void displaypath(int source, int dest)
{
    stack<int> shortpath;
    int temp = dest;
    while (temp != source) {
        shortpath.push(temp);
        temp = path[source][temp];
    }

    shortpath.push(source);
    cout<<"short distance:"<<weight[source][dest]<<endl<<"path:";
    while (!shortpath.empty()) {
        cout<<shortpath.top()<<" ";
        shortpath.pop();
    }
}

int main(int argc, char const *argv[])
{
    getData();  
    for (int i = 0;i < vertexnum;i++) {  
        for (int j = 0;j < vertexnum;j++) {  
            cout<<weight[i][j]<<"\t";  
        }  
        cout<<endl;  
    }
    floyd();
    displaypath(2,1);
    return 0;
}

