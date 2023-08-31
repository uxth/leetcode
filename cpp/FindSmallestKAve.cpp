/*
有两行input，第一行是N, K， 第二行有N个integer P_i, time limit: 2 seconds, memory limit: 256mb
1<= N <= 2*10^5
求出所有subarray的平均数然后按descending order sort, 求出第k个element是什么。
sample input:
3 3
1 2 3
sample output:
2

解释：
1 = 1
(1+2)/2 = 1.5
(1+2+3)/3 = 2
2 = 2
(2+3)/2 = 2.5
3 = 3
sort后第k个就是2.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<double> findKSmallestAve(vector<int>& input, int K)
{
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
    vector<vector<bool>> visited(input.size(), vector<bool>(input.size()));
    for(int i=0;i<input.size(); ++i)
    {
        pq.push({input[i], {i,i,input[i]}});
        visited[i][i] = true;
    }
    
    vector<double> res;
    for(int i=0; i<K && !pq.empty(); ++i)
    {
        res.push_back(pq.top().first);
        int start = pq.top().second[0];
        int end = pq.top().second[1];
        int sum = pq.top().second[2];
        pq.pop();
        if(start>0 && !visited[start-1][end])
        {
            pq.push({(double)(sum+input[start-1])/(end-start+2), {start-1, end, sum+input[start-1]}});
            visited[start-1][end]=true;
        }
        if(end<input.size()-1 && !visited[start][end+1])
        {
            pq.push({(double)(sum+input[end+1])/(end-start+2), {start, end+1, sum+input[end+1]}});
            visited[start][end+1]=true;
        }
    }
    return res;
}

int main()
{
    vector<int> input{2,1,3};
   for(auto i : findKSmallestAve(input, 6)) cout << i << ", ";
   
   return 0;
}