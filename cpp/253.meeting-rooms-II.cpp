/*

Question
Formatted question description: https://leetcode.ca/all/253.html

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
TreeMap
What is the difference between a HashMap and a TreeMap? https://stackoverflow.com/questions/2444359/what-is-the-difference-between-a-hashmap-and-a-treemap/2444370

TreeMap is an example of a SortedMap, which means that the order of the keys can be sorted, and when iterating over the keys, you can expect that they will be in order.

HashMap on the other hand, makes no such guarantee. Therefore, when iterating over the keys of a HashMap, you can’t be sure what order they will be in.

HashMap will be more efficient in general, so use it whenever you don’t care about the order of the keys.

More ref: https://www.baeldung.com/java-treemap


// incremental
@Test
public void givenTreeMap_whenOrdersEntriesNaturally_thenCorrect() {
    TreeMap<Integer, String> map = new TreeMap<>();
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");

    assertEquals("[1, 2, 3, 4, 5]", map.keySet().toString());
}

// reverse order
@Test
public void givenTreeMap_whenOrdersEntriesByComparator_thenCorrect() {
    TreeMap<Integer, String> map = 
      new TreeMap<>(Comparator.reverseOrder());
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");
        
    assertEquals("[5, 4, 3, 2, 1]", map.keySet().toString());
}

// Entry as element, customized comparator
public void givenTreeMap_whenOrdersEntriesNaturally_thenCorrect2() {

    SortedSet<Map.Entry<String, Double>> sortedset = new TreeSet<Map.Entry<String, Double>>(
                new Comparator<Map.Entry<String, Double>>() {
                    @Override
                    public int compare(Map.Entry<String, Double> e1,
                            Map.Entry<String, Double> e2) {
                        return e1.getValue().compareTo(e2.getValue());
                    }
                });

    sortedset.addAll(myMap.entrySet());
}


// usage
@Test
public void givenTreeMap_whenOrdersEntriesNaturally_thenCorrect2() {
    TreeMap<String, String> map = new TreeMap<>();
    map.put("c", "val");
    map.put("b", "val");
    map.put("a", "val");
    map.put("e", "val");
    map.put("d", "val");

    assertEquals("[a, b, c, d, e]", map.keySet().toString());
}

// usage: max/min element
@Test
public void givenTreeMap_whenPerformsQueries_thenCorrect() {
    TreeMap<Integer, String> map = new TreeMap<>();
    map.put(3, "val");
    map.put(2, "val");
    map.put(1, "val");
    map.put(5, "val");
    map.put(4, "val");

    Integer highestKey = map.lastKey();
    Integer lowestKey = map.firstKey();
    Set<Integer> keysLessThan3 = map.headMap(3).keySet();
    Set<Integer> keysGreaterThanEqTo3 = map.tailMap(3).keySet();

    assertEquals(new Integer(5), highestKey);
    assertEquals(new Integer(1), lowestKey);
    assertEquals("[1, 2]", keysLessThan3.toString());
    assertEquals("[3, 4, 5]", keysGreaterThanEqTo3.toString());
}

or, utilize Java8 Lambda api stream() and sorted()

// core is how to sort the map by it's values, i.e., sort the map (movie->count) by counts
movieToCount = movieToCount.entrySet().stream()
    .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
    .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1, LinkedHashMap::new));

Long mostViewedMovie = movieToCount.entrySet().iterator().next().getKey();
Algorithm
TreeMap
Traverse the time interval. For the start time, the mapping value is incremented by 1, and for the end time, the mapping value is decremented by 1.

Then define the result variable res, and the number of rooms rooms, traverse the TreeMap, time from small to large, add the mapping value to the number of rooms each time, and then update the result res. When the starting time is encountered, the mapping is positive, the number of rooms will increase.

If a time is the end time of one meeting and the start time of another meeting, the mapping value is decreased first and then increased and remains at 0, no new room is allocated, and the mapping value of the end time is a negative number and will not increase the number of rooms.

Heap
First sort all the time intervals according to the starting time, and then create a new minimum heap.

Start traversing the time interval. If the heap is not empty and the first element is less than or equal to the start time of the current interval, remove the first element from the heap and push the end time of the current interval into the heap.

Since the smallest heap is at the front, if the first element is less than or equal to the start time, it means that the previous meeting has ended and the meeting room can be used to start the next meeting, so there is no need to allocate a new meeting room. After the traversal is completed, the heap The number of elements is the number of meeting rooms needed.

*/

// OJ: https://leetcode.com/problems/meeting-rooms-ii/
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        vector<int> starts, ends;
        for (auto &v : A) {
            starts.push_back(v[0]);
            ends.push_back(v[1]);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        int N = A.size(), ans = 0, cnt = 0;
        for (int i = 0, j = 0; i < N;) {
            if (starts[i] < ends[j]) {
                ++cnt;
                ++i;
                ans = max(ans, cnt);
            } else if (starts[i] > ends[j]) {
                --cnt;
                ++j;
            } else {
                ++i;
                ++j;
            }
        }
        return ans;
    }

    int minMeetingRoomsBySort(vector<vector<int>>& A) {
        vector<int> data;
        for(auto& a : A) {
            data.push_back(a[0]);
            data.push_back(-a[1]);
        }
        sort(begin(data), end(data), [](int a, int b){
            return a == -b ? a < b : abs(a) < abs(b);
        });
        int res = 0;
        int cur = 0;
        for(int d : data){
            cur += d > 0 ? 1 : -1;
            res = max(res, cur);
        }
        return res;
    }
};