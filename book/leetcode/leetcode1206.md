## Intuition

跳表。skip list。

- [https://en.wikipedia.org/wiki/Skip_list](https://en.wikipedia.org/wiki/Skip_list)

----

一个 node，多个指针，相当于一行一个指针，最下面一行 base level，包含全部的元素。相当于用 rand 来实现了二分。

- search。二分搜索思路。
- add。rand 来决定高度（层数），遍历的是要存下 precursor，用来建节点的。
- erase。可能有多个，一次只删除一个。

## Solution

```cpp
struct Node {
    vector<Node*> forward;
    int val;
    Node(int val): val(val) {}
};

class Skiplist {
private:
    Node* head;
    Node* tail;
public:
    Skiplist() {
        head = new Node(0);
        tail = new Node(0);
        head->forward.push_back(tail);
    }

    bool search(int target) {
        int mx = head->forward.size();

        auto now = head;
        for (int i = mx - 1; i >= 0; i--) {
            while (now->forward[i] != tail && target > now->forward[i]->val ) {
                // go right
                now = now->forward[i];
            }

            if (now->forward[i] == tail || target < now->forward[i]->val) {
                // go down
                continue;
            } else {
                // equal
                return true;
            }
        }

        return false;
    }

    void add(int num) {
        int mx = head->forward.size();

        stack<Node*> pre;
        auto now = head;
        for (int i = mx - 1; i >= 0; i--) {
            while (now->forward[i] != tail && num >= now->forward[i]->val ) {
                // go right
                now = now->forward[i];
            }
            // go down
            pre.push(now);
        }

        Node* cur = new Node(num);
        int coinFlip = 1;
        int level = 0;
        while (coinFlip) {
            if (!pre.empty()) {
                Node* p = pre.top(); pre.pop();
                cur->forward.push_back(p->forward[level]);
                p->forward[level] = cur;
            } else {
                cur->forward.push_back(tail);
                head->forward.push_back(cur);
            }

            coinFlip = rand() & 1;
            level++;
        }

    }

    // memory leak!
    bool erase(int num) {
        int mx = head->forward.size();

        auto now = head;
        int find_flag = 0;
        for (int i = mx - 1; i >= 0; i--) {
            while (now->forward[i] != tail && num > now->forward[i]->val ) {
                // go right
                now = now->forward[i];
            }

            if (now->forward[i] == tail || num < now->forward[i]->val) {
                // go down
                continue;
            } else {
                // equal
                find_flag = find_flag | 1;

                // find next
                Node* next = now->forward[i]->forward[i];
                // while (next != tail && next->val == num) {
                //     next = next->forward[i];
                // }
                now->forward[i] = next;
            }
        }

        for (int i = mx - 1; i > 0; i--) {
            if (head->forward[i] == tail) head->forward.pop_back();
            else break;
        }

        return find_flag;
    }


};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```