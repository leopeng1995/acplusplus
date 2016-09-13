#include "route.h"
#include "lib_record.h"
#include <set>
#include <queue>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <sys/timeb.h>
#include <algorithm>
using namespace std;

const int N_OUTGOING_EDGE_MAX_SIZE = 8;
const int N_GRAPH_EDGE_MAX_SIZE = 5000;
const int N_GRAPH_NODE_MAX_SIZE = 600;
const int N_PATH_MAX_LENGTH = 600;
const int N_RUN_TIME_MAX = 19000;

unsigned short graph[N_GRAPH_NODE_MAX_SIZE][N_GRAPH_NODE_MAX_SIZE];
unsigned short outgoing_number[N_GRAPH_NODE_MAX_SIZE];
unsigned short outgoing_edge[N_GRAPH_NODE_MAX_SIZE][N_OUTGOING_EDGE_MAX_SIZE];
unsigned short line_number[N_GRAPH_NODE_MAX_SIZE][N_GRAPH_NODE_MAX_SIZE];

set<unsigned short> constraints;

int start_point = 0, end_point = 0;
int node_num = 0;

int get_time()
{
    struct timeb rawtime;
    ftime(&rawtime);

    static int ms = rawtime.millitm;
    static unsigned long s = rawtime.time;
    int out_ms = rawtime.millitm - ms;
    unsigned long out_s = rawtime.time - s;

    return 1000*out_s+out_ms;
}

typedef struct HeapNode
{
    HeapNode() : key(constraints.size()), path_num(0), total_weight(0) {}
    HeapNode(unsigned weight) : key(constraints.size()), path_num(0), total_weight(weight) {}

    void path_extend(unsigned short node);
    bool find_node(unsigned short node);

    int key;
    int path_num;
    int total_weight;

    int parent;
    int itself;

    set<unsigned short> passed_points;
    unsigned short path[N_GRAPH_NODE_MAX_SIZE];
} HeapNode;

void HeapNode::path_extend(unsigned short node)
{
    path[path_num++] = node;
    passed_points.insert(node);
 
    if (constraints.find(node) != constraints.end())
        key--;
    
    if (path_num > 1)
        total_weight = total_weight + graph[path[path_num - 2]][node];
}

bool HeapNode::find_node(unsigned short node)
{
    if (passed_points.find(node) != passed_points.end())
        return true;
    return false;
}

struct compare {
    bool operator()(const HeapNode &node1, const HeapNode &node2) const {
        if (node1.key != node2.key) return node1.key > node2.key;
        return node1.total_weight > node2.total_weight;
    }
};

void edge_prepare(char *topo[N_GRAPH_EDGE_MAX_SIZE], int edge_num)
{ for (int i = 0; i < edge_num; ++i)
    {
        int j = 0, line_num = 0, line_start = 0, line_end = 0, line_weight = 0;
        while (topo[i][j] != ',') { line_num = line_num * 10 + topo[i][j] - 48; j++; }
        j++;
        while (topo[i][j] != ',') { line_start = line_start * 10 + topo[i][j] - 48; j++; }
        j++;
        while (topo[i][j] != ',') { line_end = line_end * 10 + topo[i][j] - 48; j++; }
        j++;

            while (topo[i][j] != '\n'&&topo[i][j] != '\0') { line_weight = line_weight * 10 + topo[i][j] - 48; j++; }

        node_num = max((int)node_num, max(line_start, line_end));
        

        if (graph[line_start][line_end] == 0)
        {
            line_number[line_start][line_end] = line_num;
            outgoing_edge[line_start][outgoing_number[line_start]] = line_end;
            outgoing_number[line_start]++;
            graph[line_start][line_end] = line_weight;
        }
        else
        {
            if (graph[line_start][line_end] > line_weight)
            {
                line_number[line_start][line_end] = line_num;
                graph[line_start][line_end] = line_weight;
            }
        }
    }
    node_num = node_num + 1;
}

void demand_prepare(char *demand)
{
    int j = 0;
    while (demand[j] != ',') {  start_point = start_point * 10 + demand[j] - 48; j++; }
    j++;
    while (demand[j] != ',') { end_point =end_point * 10 + demand[j] - 48; j++; }

    while (demand[j] != '\0' && demand[j] != '\n')
    {
        j++;
        int constraint_point = 0;
        while (demand[j] != '|' && demand[j] != '\0' && demand[j] != '\n')
        {
            constraint_point = constraint_point * 10 + demand[j] - 48;
            j++;
        }
        constraints.insert(constraint_point);
    }
}

//你要完成的功能总入口
void search_route(char *topo[5000], int edge_num, char *demand)
{
    edge_prepare(topo, edge_num);
    demand_prepare(demand);
    for (int i = 0; i < node_num; i++)
    {
        for(int j = 0;j < node_num; j++)
            printf("%d  ", graph[i][j]);
        printf("\n");
    }

    for (int i = 0;i < node_num; i++)
        printf("%d\n",outgoing_number[i]);

    for (int i = 0; i < node_num; i++)
    {
        for(int j = 0; j < outgoing_number[i]; j++)
            printf("%d\t", outgoing_edge[i][j]);
        printf("\n");
    }

    HeapNode root;
    root.path_extend(start_point);
    priority_queue<HeapNode, vector<HeapNode>, compare> heap;
    heap.push(root);
    unsigned int Me = 20000000;
    HeapNode ans(N_PATH_MAX_LENGTH);
    int time_begin, time_end;
    time_begin = get_time(); 

    while (!heap.empty())
    {
        HeapNode top = heap.top();
        heap.pop();
        int u = top.path[top.path_num - 1];
        for (int i = 0; i < top.path_num; i++) printf("%d ", top.path[i]);
        if (top.total_weight >= ans.total_weight) continue;

        printf("\n");
        int outgoing_num = outgoing_number[u];

        for (int i = 0; i < outgoing_num; i++)
        {
            if (top.find_node(outgoing_edge[u][i])) continue;
            if (top.key > 0 && outgoing_edge[u][i] == end_point) continue;

            HeapNode node;
            node=top;
            node.path_extend(outgoing_edge[u][i]);

            int u = node.path[node.path_num-1];
            if (u == end_point && node.key == 0&&node.total_weight < ans.total_weight)
            {
                ans = node;
                continue;
            }
            if (node.total_weight < ans.total_weight) heap.push(node);

            time_end = get_time();
            if (heap.size() >= Me || (time_end - time_begin >= N_RUN_TIME_MAX)) break;
        }
        
        if (heap.size() >= Me || (time_end - time_begin >= N_RUN_TIME_MAX)) break;
    }

    if (ans.total_weight != N_PATH_MAX_LENGTH)
    {
        for (int i = 0; i <ans.path_num - 1; i++)
        {
            int prev = ans.path[i], next = ans.path[i + 1];
            record_result(line_number[prev][next]);
        }
    }
}
