/*

Question
Formatted question description: https://leetcode.ca/all/353.html

Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:

SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.
 

Example 1:



Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]

Explanation
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // return 0
snakeGame.move("D"); // return 0
snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
snakeGame.move("U"); // return 1
snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
snakeGame.move("U"); // return -1, game over because snake collides with border

 

Constraints:

1 <= width, height <= 104
1 <= food.length <= 50
food[i].length == 2
0 <= ri < height
0 <= ci < width
direction.length == 1
direction is 'U', 'D', 'L', or 'R'.
At most 104 calls will be made to move.
Algorithm
We need a one-dimensional array to store the position of the snake body.

As the head of the snake moves forward a step, the tail of the snake also moves forward, and the body in the middle is still in its original position. As a result of the movement, the head of the snake changes to a new position, removing the position of the tail.

What needs attention is whether the position of removing the snake tail is before or after detecting the collision with the snake body.

If it is later, you cannot pass this test case: [[3,3,[[2,0],[0,0]]],["D"],["D"],["U"]] ,
If it is before, there is no problem To detect whether the snake head and the snake body collide, use count(snake.begin(), snake.end(), head)

*/

class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height;
        n = width;
        this->food = food;
        score = 0;
        idx = 0;
        q.push_back(0);
        vis.insert(0);
    }

    int move(string direction) {
        int p = q.front();
        int i = p / n, j = p % n;
        int x = i, y = j;
        if (direction == "U") {
            --x;
        } else if (direction == "D") {
            ++x;
        } else if (direction == "L") {
            --y;
        } else {
            ++y;
        }
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return -1;
        }
        if (idx < food.size() && x == food[idx][0] && y == food[idx][1]) {
            ++score;
            ++idx;
        } else {
            int tail = q.back();
            q.pop_back();
            vis.erase(tail);
        }
        int cur = f(x, y);
        if (vis.count(cur)) {
            return -1;
        }
        q.push_front(cur);
        vis.insert(cur);
        return score;
    }

private:
    int m;
    int n;
    vector<vector<int>> food;
    int score;
    int idx;
    deque<int> q;
    unordered_set<int> vis;

    int f(int i, int j) {
        return i * n + j;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
