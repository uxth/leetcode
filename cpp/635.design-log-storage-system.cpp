/*

Description
You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log’s unique id and timestamp, store the log in your storage system.

int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start and end all have the same format as timestamp. However, granularity means the time level for consideration. For example, start = “2017:01:01:23:59:59”, end = “2017:01:02:23:59:59”, granularity = “Day”, it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.

Example 1:

put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
Note:

There will be at most 300 operations of Put or Retrieve.
Year ranges from [2000,2017]. Hour ranges from [00,23].
Output for Retrieve has no order required.
Solution
Use a tree map to store each log’s timestamp and id, where the entries are sorted according to the timestamps.

For put, add an entry into the tree map where timestamp is the key and id is the value.

For retrieve, first change s and e to the needed formats according to granularity, and increase the changed e by 1, and then obtain all the entries from the tree map, and finally add all the ids to a list and return.

treeMap.tailMap(start);

*/


class LogSystem {
public:
    LogSystem() {
        d["Year"] = 4;
        d["Month"] = 7;
        d["Day"] = 10;
        d["Hour"] = 13;
        d["Minute"] = 16;
        d["Second"] = 19;
    }

    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ans;
        int i = d[granularity];
        auto s = start.substr(0, i);
        auto e = end.substr(0, i);
        for (auto& [id, ts] : logs) {
            auto t = ts.substr(0, i);
            if (s <= t && t <= e) {
                ans.emplace_back(id);
            }
        }
        return ans;
    }

private:
    vector<pair<int, string>> logs;
    unordered_map<string, int> d;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */