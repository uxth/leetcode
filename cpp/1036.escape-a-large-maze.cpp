/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 *
 * https://leetcode.com/problems/escape-a-large-maze/description/
 *
 * algorithms
 * Hard (35.37%)
 * Likes:    235
 * Dislikes: 101
 * Total Accepted:    10.2K
 * Total Submissions: 29K
 * Testcase Example:  '[[0,1],[1,0]]\n[0,0]\n[0,2]'
 *
 * In a 1 million by 1 million grid, the coordinates of each grid square are
 * (x, y) with 0 <= x, y < 10^6.
 * 
 * We start at the source square and want to reach the target square.  Each
 * move, we can walk to a 4-directionally adjacent square in the grid that
 * isn't in the given list of blocked squares.
 * 
 * Return true if and only if it is possible to reach the target square through
 * a sequence of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
 * Output: false
 * Explanation: 
 * The target square is inaccessible starting from the source square, because
 * we can't walk outside the grid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: blocked = [], source = [0,0], target = [999999,999999]
 * Output: true
 * Explanation: 
 * Because there are no blocked cells, it's possible to reach the target
 * square.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= blocked.length <= 200
 * blocked[i].length == 2
 * 0 <= blocked[i][j] < 10^6
 * source.length == target.length == 2
 * 0 <= source[i][j], target[i][j] < 10^6
 * source != target
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int MAX = 1e6;
    vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    // bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    //     priority_queue<pair<long, pair<int,int>>, vector<pair<long, pair<int,int>>>, greater<pair<long, pair<int,int>>>> pq;
        
    //     unordered_set<long> blk;
    //     for(auto& b : blocked)blk.insert(((long)b[0]<<32) + b[1]);
    //     long dis = (long)(target[0]-source[0]) * (long)(target[0]-source[0]) + (long)(target[1]-source[1])*(long)(target[1]-source[1]);
    //     pq.push({dis, {source[0], source[1]}});
    //     //pq.push({dis, {target[0], target[1]}});
    //     unordered_set<long> closed{((long)source[0]<<32)+source[1]};
    //     while(!pq.empty())
    //     {
    //         long dis = pq.top().first;
    //         int y = pq.top().second.first;
    //         int x = pq.top().second.second;
    //         pq.pop();
    //         cout << y << " " << x << " " << dis << endl;
    //         for(auto& d: dir)
    //         {
    //             int ny=y+d.first;
    //             int nx=x+d.second;
                
    //             if(ny<0||nx<0||ny>=MAX||nx>=MAX)continue;
    //             long nn = ((long)ny<<32)+nx;
    //             if(closed.count(nn)||blk.count(nn))continue;
    //             if(ny==target[0] && nx==target[1]) return true;
    //             closed.insert(nn);
    //             long ds = ((long)ny-target[0])*((long)ny-target[0]) + ((long)nx-target[1])*((long)nx-target[1]);
    //             pq.push({ds, {ny,nx}});
    //         }
    //     } 
    //     return false;
    // }

    /*
    bool step(priority_queue<pair<long, pair<int,int>>, vector<pair<long, pair<int,int>>>, greater<pair<long, pair<int,int>>>>& q, unordered_set<pair<int,int>, pair_hash>& visited, unordered_set<pair<int,int>, pair_hash>& inter, unordered_set<pair<int,int>,pair_hash>& blk, vector<int>& t)
    {
        unordered_set<pair<int,int>, pair_hash> nextinter;
        int size = q.size();
        for(int i=0; i<size; ++i)
        {
            long d = q.top().first;
            int y0=q.top().second.first;
            int x0=q.top().second.second;
            q.pop();
            for(auto& d : dir)
            {
                long ny=y0+d.first;
                long nx=x0+d.second;
                if(ny<0||nx<0||ny>=MAX||nx>=MAX) continue;
                if(visited.count({ny,nx}) || blk.count({ny,nx})) continue;
                if(inter.count({ny,nx})) return true;
                nextinter.insert({ny,nx});
                visited.insert({ny,nx});
                long dis = (ny-t[0])*(ny-t[0])+(nx-t[1])*(nx-t[1]);
                q.push({dis, {ny,nx}});
            }
        }
        swap(inter, nextinter);
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()) return true;
        long D = pow((long)target[0]-source[0], 2)+pow((long)target[1]-source[1], 2);
        priority_queue<pair<long, pair<int,int>>, vector<pair<long, pair<int,int>>>, greater<pair<long, pair<int,int>>>> fw; fw.push({D,{source[0],source[1]}});
        priority_queue<pair<long, pair<int,int>>, vector<pair<long, pair<int,int>>>, greater<pair<long, pair<int,int>>>> bw; bw.push({D,{target[0],target[1]}});
        unordered_set<pair<int,int>,pair_hash> blk;
        for(auto& b : blocked) blk.insert({b[0],b[1]});
        unordered_set<pair<int,int>,pair_hash> inter{{target[0],target[1]}};
        unordered_set<pair<int,int>,pair_hash> fv{{source[0],source[1]}}, bv{{target[0],target[1]}};
        int move=0;
        while(!fw.empty() && !bw.empty())
        {
            if(move%2==0?step(fw, fv, inter, blk, target):step(bw,bv, inter, blk, source)) return true;
            move++;
        }
        return false;
    }

    */

    bool canblockV(vector<int>& pos, unordered_set<pair<int,int>,pair_hash>& blk)
    {
        auto feel= [&](int i){
            int y=pos[0];
            queue<int> q; q.push(pos[1]);
            while(!q.empty())
            {
                int size=q.size();
                while(size--)
                {
                    int x = q.front(); q.pop();
                    if(x==0 || x>=MAX || y==0 || y>=MAX) return true;
                    for(int j=-1; j<=1; j++)
                        if(blk.count({y+i, x+j})) 
                            q.push(x+j);
                }
                y+=i;
            }
            return false;
        };
        return feel(-1) && feel(1);

    }
    bool canblockH(vector<int>& pos, unordered_set<pair<int,int>,pair_hash>& blk)
    {
        auto feel = [&](int j){
            int x=pos[1];
            queue<int> q; q.push(pos[0]);
            while(!q.empty())
            {
                int size = q.size();
                while(size--)
                {
                    int y = q.front(); q.pop();
                    if(x==0 || x>=MAX || y==0 || y>=MAX) return true;
                    for(int i=-1; i<=1; i++)
                        if(blk.count({y+i, x+j}))
                            q.push(y+i);
                }
                x+=j;
            }
            return false;
        };
        return feel(-1) && feel(1);
    }
    bool surrounded(vector<int>& pos, unordered_set<pair<int,int>, pair_hash>& blk)
    {
        
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<pair<int,int>,pair_hash> blk;
        for(auto& b: blocked)blk.insert({b[0],b[1]});
        for(auto& b: blocked)
        {
            long t0 = b[0]-source[0];
            long t1 = b[0]-target[0];
            if(t0*t1<=0)
            {
                if(canblockV(b, blk)) return false;
            }
            t0 = b[1]-source[1];
            t1 = b[1]-target[1];
            if(t0*t1<=0)
            {
                if(canblockH(b, blk)) return false;
            }
        }
        return true;
    }
};
// @lc code=end

//  []\n[0,0]\n[999999,999999]
// []\n[0,0]\n[9,9]
// [[691938,300406],[710196,624190],[858790,609485],[268029,225806],[200010,188664],[132599,612099],[329444,633495],[196657,757958],[628509,883388]]\n[655988,180910]\n[267728,840949]

// [[100059,100063],[100060,100064],[100061,100065],[100062,100066],[100063,100067],[100064,100068],[100065,100069],[100066,100070],[100067,100071],[100068,100072],[100069,100073],[100070,100074],[100071,100075],[100072,100076],[100073,100077],[100074,100078],[100075,100079],[100076,100080],[100077,100081],[100078,100082],[100079,100083],[100080,100082],[100081,100081],[100082,100080],[100083,100079],[100084,100078],[100085,100077],[100086,100076],[100087,100075],[100088,100074],[100089,100073],[100090,100072],[100091,100071],[100092,100070],[100093,100069],[100094,100068],[100095,100067],[100096,100066],[100097,100065],[100098,100064],[100099,100063],[100098,100062],[100097,100061],[100096,100060],[100095,100059],[100094,100058],[100093,100057],[100092,100056],[100091,100055],[100090,100054],[100089,100053],[100088,100052],[100087,100051],[100086,100050],[100085,100049],[100084,100048],[100083,100047],[100082,100046],[100081,100045],[100080,100044],[100079,100043],[100078,100044],[100077,100045],[100076,100046],[100075,100047],[100074,100048],[100073,100049],[100072,100050],[100071,100051],[100070,100052],[100069,100053],[100068,100054],[100067,100055],[100066,100056],[100065,100057],[100064,100058],[100063,100059],[100062,100060],[100061,100061],[100060,100062]]\n[100079,100063]\n[999948,999967]