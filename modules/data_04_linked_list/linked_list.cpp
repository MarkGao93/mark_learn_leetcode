#include "common.h"
#include "linked_list.h"
#include <stack>
// #include <string>
// #include <assert.h>
// #include <algorithm>
// #include <queue>
#include <unordered_set>
// #include <unordered_map>
using std::vector;
// using std::string;
using std::unordered_set;
// using std::unordered_map;
// using std::pair;
// using std::sort;
using std::swap;
// using std::reverse;
using std::stack;





class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode () : val(0), next(nullptr) {}
        LinkedNode (int x) : val(x), next(nullptr) {}
        LinkedNode (int x, LinkedNode  *next) : val(x), next(next) {}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode (0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) { // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;  // addAtHead(val)
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // delete命令指示释放了tmp指针原本所指的那部分内存，
        // 被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        // 如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        // 如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp = nullptr;
        _size--;
    }

    // 删除链表中所有满足 Node.val == val 的节点
    void removeAtVal(int val) {
        LinkedNode * cur = _dummyHead;
        while (cur->next != nullptr) {  // while (cur->next)
            if (cur->next->val == val) {
                LinkedNode * tmp = cur->next;
                cur->next = cur->next->next;
                _size--;
                delete tmp;
                tmp = nullptr;
            } else {
                cur = cur->next;
            }
        }
    }

    // 反转链表
    void reverseList() {
        // 方法一：双指针法
        LinkedNode* temp; // 保存cur的下一个节点
        LinkedNode* cur = _dummyHead->next;
        LinkedNode* pre = nullptr;
        while (cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        _dummyHead->next = pre;

        // 方法二：递归法
        // TODO: 递归实现
    }

    // 两两交换节点
    void swapPairs() {
        // 步骤一，cur指向next的next
        // 步骤二，next的next指向next
        // 步骤三，next指向next的next的next
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            LinkedNode* temp1 = cur->next;  // 记录临时节点
            LinkedNode* temp3 = cur->next->next->next;  // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = temp1;        // 步骤二
            cur->next->next->next = temp3;  // 步骤三
            cur = cur->next->next;  // cur移动两位，准备下一轮交换
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)
    }
    
    // 删除倒数第N个节点
    void removeNthFromEnd(int n) {
        LinkedNode* fast = _dummyHead;
        LinkedNode* slow = _dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;  // 快指针先走n步
        }
        fast = fast->next;  // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != nullptr) {  // 快慢指针同时移动
            fast = fast->next;
            slow = slow->next;
        }
        LinkedNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        temp = nullptr;
        _size--;
    }

    // 判断链表是否有环
    bool detectCycle() {
        unordered_set<LinkedNode*> visited;
        LinkedNode* cur = _dummyHead->next;
        while (cur != nullptr) {
            if (visited.count(cur)) {
                return true;
            }
            visited.insert(cur);
            cur = cur->next;
        }
        return false;
    }

    // 判断链表是否为回文链表
    bool isPalindrome() {
        LinkedNode* cur  = _dummyHead->next;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }
        vector<int> vec(length, 0); // 给定vector的初始长度，这样避免vector每次添加节点重新开辟空间
        cur = _dummyHead->next;
        int index = 0;
        while (cur) {
            vec[index++] = cur->val;
            cur = cur->next;
        }
        // 比较数组回文
        for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            if (vec[i] != vec[j]) return false;
        }
        return true;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        cout << "current listedlist is: ";
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
        cout << "current listedlist size is: " << _size << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};

void linked_list_leetcode();
// Carl Lesson
void leetcode_203();
void leetcode_707();
void leetcode_206();
void leetcode_24();
void leetcode_19();
void leetcode_160();
void leetcode_142();

// LeetCode Hot 100
void leetcode_234();
void leetcode_141();
void leetcode_21();

// LeetCode Classic 150


int linked_list_main() {
    cout << endl << "linked_list_main" << endl << endl;

    linked_list_leetcode();

    // 我自己的链表类
    MyLinkedList myLinkedList;
    cout << endl << "myLinkedList add initial nodes: " << endl;
    myLinkedList.addAtHead(1);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(1, 2);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(2, 6);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(3, 3);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(4, 4);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(5, 5);
    // myLinkedList.printLinkedList();
    myLinkedList.addAtIndex(6, 6);
    myLinkedList.addAtTail(610);
    myLinkedList.printLinkedList();

    cout << "myLinkedList get 0: " << myLinkedList.get(0) << endl;
    cout << "myLinkedList get 10: " << myLinkedList.get(10) << endl;
    cout << "myLinkedList get 5: " << myLinkedList.get(5) << endl;

    cout << endl << "myLinkedList deleteAtIndex 1: " << endl;
    myLinkedList.deleteAtIndex(1);
    myLinkedList.printLinkedList();

    cout << endl << "myLinkedList removeElements val = 6: " << endl;
    myLinkedList.removeAtVal(6);
    myLinkedList.printLinkedList();

    cout << endl << "reverse myLinkedList: " << endl;
    myLinkedList.reverseList();
    myLinkedList.printLinkedList();

    cout << endl << "myLinkedList swap pairs: " << endl;
    myLinkedList.swapPairs();
    myLinkedList.printLinkedList();

    cout << endl << "add more nodes: " << endl;
    myLinkedList.addAtIndex(3, 7);
    myLinkedList.addAtTail(11);
    myLinkedList.printLinkedList();
    cout << endl << "myLinkedList removeNthFromEnd 2: " << endl;
    myLinkedList.removeNthFromEnd(2);
    myLinkedList.printLinkedList();
    cout << endl << "myLinkedList removeNthFromEnd 5: " << endl;
    myLinkedList.removeNthFromEnd(5);
    myLinkedList.printLinkedList();

    cout << endl << "myLinkedList detectCycle: " << endl;
    bool ret = myLinkedList.detectCycle();
    myLinkedList.printLinkedList();
    cout << "myLinkedList detectCycle: " << ret << endl;

    cout << endl << "myLinkedList add more nodes at tail: " << endl;
    myLinkedList.addAtTail(4);
    myLinkedList.addAtTail(7);
    myLinkedList.addAtTail(3);
    myLinkedList.printLinkedList();
    cout << endl << "myLinkedList isPalindrome: " << myLinkedList.isPalindrome() << endl;
    myLinkedList.addAtTail(5);
    myLinkedList.printLinkedList();
    cout << "myLinkedList isPalindrome: " << myLinkedList.isPalindrome() << endl;
    

    return 0;
}


void linked_list_leetcode() {
    // Carl Lessons
    leetcode_203();  // 移除链表元素, simple
    leetcode_707();  // 设计链表, medium
    leetcode_206();  // 反转链表, simple, Hot100
    leetcode_24();  // 两两交换链表中的节点, medium, Hot100
    leetcode_19();  // 删除链表的倒数第N个节点, medium, Hot100, Classic150
    leetcode_160();  // 相交链表, simple, Hot100
    leetcode_142();  // 环形链表II, medium, Hot100

    // LeetCode Hot 100
    // leetcode_160();  // 相交链表, simple, Hot100
    // leetcode_206();  // 反转链表, simple, Hot100
    leetcode_234();  // 回文链表, simple, Hot100
    leetcode_141();  // 环形链表, simple, Hot100
    // leetcode_142();  // 环形链表II, medium, Hot100
    leetcode_21();  // 合并两个有序链表, simple, Hot100, Classic150

    // LeetCode Classic 150
    
}

///////////////////////////////////////////////////////////////////////////////
// 移除链表元素，simple
///////////////////////////////////////////////////////////////////////////////
void leetcode_203() {
    cout << endl << "leetcode_203" << endl;    
    // 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点。
    // 输入: head = [1,2,6,3,4,5,6], val = 6
    // 输出: [1,2,3,4,5]
    // Carl: https://www.programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html
    // leetcode: https://leetcode.cn/problems/remove-linked-list-elements/description/

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一（推荐）：设置一个虚拟头结点再进行移除节点操作
        ListNode* removeElements(ListNode* head, int val) {
            ListNode * dummyHead = new ListNode(0);  // 设置一个虚拟头结点
            dummyHead->next = head;  // 将虚拟头结点指向head，这样方便后面做删除操作
            ListNode * cur = dummyHead;
            while (cur->next != nullptr) {  // while (cur->next)
                if (cur->next->val == val) {
                    ListNode * tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                    // tmp = nullptr;
                } else {
                    cur = cur->next;
                }
            }
            head = dummyHead->next;
            delete dummyHead;
            // dummyHead = nullptr;
            return head;
            // 时间复杂度: O(n)
            // 空间复杂度: O(1)

            // 方法二：直接使用原来的链表来进行移除节点操作
            // if (method2) {
            // 删除头结点
            // while (head != nullptr && head->val == val) {  // 注意这里不是if
            //     ListNode * tmp = head;
            //     head = head->next;
            //     delete tmp;
            //     // tmp = nullptr;
            // }

            // // 删除非头结点
            // ListNode * cur = head;
            // while (cur != nullptr && cur->next!= nullptr) {
            //     if (cur->next->val == val) {
            //         ListNode * tmp = cur->next;
            //         cur->next = cur->next->next;
            //         delete tmp;
            //         // tmp = nullptr;
            //     } else {
            //         cur = cur->next;
            //     }
            // }
            // return head;        
            // 时间复杂度: O(n)
            // 空间复杂度: O(1)
            // } 

            // 方法三：递归法
            // TODO: 递归实现
        }

        
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 设计链表，medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_707() {
    cout << endl << "leetcode_707" << endl;
    // 你可以选择使用单链表或者双链表，设计并实现自己的链表。
    // 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
    // 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
    // 实现 MyLinkedList 类：
    // MyLinkedList() 初始化 MyLinkedList 对象。
    // int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
    // void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    // void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    // void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
    // void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
    // Carl: https://www.programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html
    // leetcode: https://leetcode.cn/problems/design-linked-list/description/

    class MyLinkedList {
    public:
        // 定义链表节点结构体
        struct LinkedNode {
            int val;
            LinkedNode* next;
            LinkedNode(int val):val(val), next(nullptr){}
        };

        // 初始化链表
        MyLinkedList() {
            _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
            _size = 0;
        }

        // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
        int get(int index) {
            if (index > (_size - 1) || index < 0) {
                return -1;
            }
            LinkedNode* cur = _dummyHead->next;
            while(index--){ // 如果--index 就会陷入死循环
                cur = cur->next;
            }
            return cur->val;
        }

        // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
        void addAtHead(int val) {
            LinkedNode* newNode = new LinkedNode(val);
            newNode->next = _dummyHead->next;
            _dummyHead->next = newNode;
            _size++;
        }

        // 在链表最后面添加一个节点
        void addAtTail(int val) {
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while(cur->next != nullptr){
                cur = cur->next;
            }
            cur->next = newNode;
            _size++;
        }

        // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
        // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
        // 如果index大于链表的长度，则返回空
        // 如果index小于0，则在头部插入节点
        void addAtIndex(int index, int val) {

            if(index > _size) return;
            if(index < 0) index = 0;        
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while(index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }

        // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
        void deleteAtIndex(int index) {
            if (index >= _size || index < 0) {
                return;
            }
            LinkedNode* cur = _dummyHead;
            while(index--) {
                cur = cur ->next;
            }
            LinkedNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            //delete命令指示释放了tmp指针原本所指的那部分内存，
            //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
            //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
            //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
            tmp=nullptr;
            _size--;
        }

        // 打印链表
        void printLinkedList() {
            LinkedNode* cur = _dummyHead;
            while (cur->next != nullptr) {
                cout << cur->next->val << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    private:
        int _size;
        LinkedNode* _dummyHead;
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 反转链表，simple
///////////////////////////////////////////////////////////////////////////////
void leetcode_206() {
    cout << endl << "leetcode_206" << endl;    
    // 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
    // 输入: head = [1,2,3,4,5]
    // 输出: [5,4,3,2,1]
    // Carl: https://www.programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html
    // leetcode: https://leetcode.cn/problems/reverse-linked-list/description/

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：迭代法/双指针法
        // 首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。
        // 然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。
        // 为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。
        // 接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。
        // 最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。
        ListNode* reverseList1(ListNode* head) {
            ListNode* temp;  // 保存cur的下一个节点
            ListNode* cur = head;
            ListNode* pre = nullptr;
            while (cur) {
                temp = cur->next;
                cur->next = pre;  // 翻转操作
                // 更新pre 和 cur指针
                pre = cur;
                cur = temp;
            }
            return pre;
        }
        // 时间复杂度: O(n)
        // 空间复杂度: O(1)

        // 方法二：递归法
        // 递归法相对抽象一些，但是其实和双指针法是一样的逻辑，同样是当cur为空的时候循环结束，不断将cur指向pre的过程。
        ListNode* reverse(ListNode* pre, ListNode* cur){
            if (cur == nullptr) return pre;
            ListNode* temp = cur->next;
            cur->next = pre;
            // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
            // pre = cur;
            // cur = temp;
            return reverse(cur,temp);
        }
        ListNode* reverseList2(ListNode* head) {
            // 和双指针法初始化是一样的逻辑
            // ListNode* cur = head;
            // ListNode* pre = NULL;
            return reverse(nullptr, head);
        }
        // 时间复杂度: O(n), 要递归处理链表的每个节点
        // 空间复杂度: O(n), 递归调用了 n 层栈空间

        // 方法三：递归法（从后向前反转）
        ListNode* reverseList3(ListNode* head) {
            // 边缘条件判断
            if(head == nullptr) return nullptr;
            if (head->next == nullptr) return head;
            
            // 递归调用，翻转第二个节点开始往后的链表
            ListNode *last = reverseList3(head->next);
            // 翻转头节点与第二个节点的指向
            head->next->next = head;
            // 此时的 head 节点为尾节点，next 需要指向 NULL
            head->next = nullptr;
            return last;
        }
        // 时间复杂度: O(n)
        // 空间复杂度: O(n)
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 两两交换链表中的节点，medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_24() {
    cout << endl << "leetcode_24" << endl;    
    // 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
    // 输入: head = [1,2,3,4]
    // 输出: [2,1,4,3]
    // Carl: https://www.programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html
    // leetcode: https://leetcode.cn/problems/swap-nodes-in-pairs/description/

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 建议使用虚拟头结点，这样会方便很多，要不然每次针对头结点（没有前一个指针指向头结点），还要单独处理。
        // 初始时，cur指向虚拟头结点，然后进行如下三步：
        // 步骤一，cur指向next的next
        // 步骤二，next的next指向next
        // 步骤三，next指向next的next的next
        ListNode* swapPairs(ListNode* head) {
            ListNode* dummyHead = new ListNode(0);  // 设置一个虚拟头结点
            dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
            ListNode* cur = dummyHead;
            while (cur->next != nullptr && cur->next->next != nullptr) {
                ListNode* temp1 = cur->next;  // 记录临时节点
                ListNode* temp3 = cur->next->next->next;  // 记录临时节点
                cur->next = cur->next->next;    // 步骤一
                cur->next->next = temp1;        // 步骤二
                cur->next->next->next = temp3;  // 步骤三
                cur = cur->next->next;  // cur移动两位，准备下一轮交换
            }
            return dummyHead->next;
            // 时间复杂度：O(n)
            // 空间复杂度：O(1)
        }
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 删除链表的倒数第N个节点，medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_19() {
    cout << endl << "leetcode_19" << endl;    
    // 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    // 输入: head = [1,2,3,4,5], n = 2
    // 输出: [1,2,3,5]
    // Carl: https://www.programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html
    // leetcode: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：计算链表长度
        // 一种容易想到的方法是，我们首先从头节点开始对链表进行一次遍历，得到链表的长度 L。
        // 随后我们再从头节点开始对链表进行一次遍历，当遍历到第 L−n+1 个节点时，它就是我们需要删除的节点。
        // 为了方便删除操作，我们可以从哑节点开始遍历 L−n+1个节点。当遍历到第 L−n+1个节点时，
        // 它的下一个节点就是我们需要删除的节点，这样我们只需要修改一次指针，就能完成删除操作。
        int getLength(ListNode* head) {
            int length = 0;
            while (head) {
                ++length;
                head = head->next;
            }
            return length;
        }

        ListNode* removeNthFromEnd1(ListNode* head, int n) {
            ListNode* dummy = new ListNode(0, head);
            int length = getLength(head);
            ListNode* cur = dummy;
            for (int i = 1; i < length - n + 1; ++i) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
            ListNode* ans = dummy->next;
            delete dummy;
            return ans;
        }

        // 方法二：双指针法
        // 如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。删掉slow所指向的节点就可以了。
        // 首先这里我推荐大家使用虚拟头结点，这样方便处理删除实际头结点的逻辑
        // 定义fast指针和slow指针，初始值为虚拟头结点
        // fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作）
        // fast和slow同时移动，直到fast指向末尾
        // 删除slow指向的下一个节点
        ListNode* removeNthFromEnd2(ListNode* head, int n) {
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode* slow = dummyHead;
            ListNode* fast = dummyHead;
            while(n-- && fast != nullptr) {
                fast = fast->next;
            }
            fast = fast->next;  // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
            while (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next; 
            
            // ListNode *tmp = slow->next;  C++释放内存的逻辑
            // slow->next = tmp->next;
            // delete nth;
            
            return dummyHead->next;            
            // 时间复杂度：O(n)
            // 空间复杂度：O(1)
        }

        // 方法三：栈
        // 我们也可以在遍历链表的同时将所有节点依次入栈。
        // 根据栈「先进后出」的原则，我们弹出栈的第 n 个节点就是需要删除的节点，并且目前栈顶的节点就是待删除节点的前驱节点。
        // 这样一来，删除操作就变得十分方便了。
        ListNode* removeNthFromEnd3(ListNode* head, int n) {
            ListNode* dummy = new ListNode(0, head);
            stack<ListNode*> stk;
            ListNode* cur = dummy;
            while (cur) {
                stk.push(cur);
                cur = cur->next;
            }
            for (int i = 0; i < n; ++i) {
                stk.pop();
            }
            ListNode* prev = stk.top();
            prev->next = prev->next->next;
            ListNode* ans = dummy->next;
            delete dummy;
            return ans;
            // 时间复杂度：O(L)，其中 L 是链表的长度。
            // 空间复杂度：O(L)，其中 L 是链表的长度。主要为栈的开销。
        }

    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 相交链表，simple，Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_160() {
    cout << endl << "leetcode_160" << endl;    
    // 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
    // 如果两个链表不存在相交节点，返回 null 。
    // 输入: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
    // 输出: Intersected at '8'
    // Carl: https://www.programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF
    // leetcode: https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：哈希集合
        // 判断两个链表是否相交，可以使用哈希集合存储链表节点。
        // 首先遍历链表 headA，并将链表 headA中的每个节点加入哈希集合中。
        // 然后遍历链表 headB，对于遍历到的每个节点，判断该节点是否在哈希集合中：
        // 如果当前节点不在哈希集合中，则继续遍历下一个节点；
        // 如果当前节点在哈希集合中，则后面的节点都在哈希集合中，即从当前节点开始的所有节点都在两个链表的相交部分，
        // 因此在链表 headB中遍历到的第一个在哈希集合中的节点就是两个链表相交的节点，返回该节点。
        // 如果链表 headB 中的所有节点都不在哈希集合中，则两个链表不相交，返回 null。
        ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
            unordered_set<ListNode *> visited;
            ListNode *temp = headA;
            while (temp != nullptr) {
                visited.insert(temp);
                temp = temp->next;
            }
            temp = headB;
            while (temp != nullptr) {
                if (visited.count(temp)) {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }
        // 时间复杂度：O(m+n)，其中 m 和 n 是分别是链表 headA和 headB 的长度。需要遍历两个链表各一次。
        // 空间复杂度：O(m)，其中 m 是链表 headA 的长度。需要使用哈希集合存储链表 headA 中的全部节点。

        // 方法二：双指针法
        // 当链表 headA 和 headB 都不为空时，创建两个指针 pA 和 pB，初始时分别指向两个链表的头节点 headA 和 headB
        // 然后将两个指针依次遍历两个链表的每个节点。具体做法如下：
        // 每步操作需要同时更新指针 pA 和 pB。
        // 如果指针 pA 不为空，则将指针 pA 移到下一个节点；如果指针 pB 不为空，则将指针 pB 移到下一个节点。
        // 如果指针 pA 为空，则将指针 pA 移到链表 headB 的头节点；如果指针 pB 为空，则将指针 pB 移到链表 headA 的头节点。
        // 当指针 pA 和 pB 指向同一个节点或者都为空时，返回它们指向的节点或者 null。
        ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
            if (headA == nullptr || headB == nullptr) {
                return nullptr;
            }
            ListNode *pA = headA, *pB = headB;
            while (pA != pB) {
                pA = pA == nullptr ? headB : pA->next;
                pB = pB == nullptr ? headA : pB->next;
            }
            return pA;
        }
        // 时间复杂度：O(m+n)，其中 m 和 n 是分别是链表 headA和 headB 的长度。两个指针同时遍历两个链表，每个指针遍历两个链表各一次。
        // 空间复杂度：O(1)。

        // 方法三：末尾对其法
        // 我们求出两个链表的长度，并求出两个链表长度的差值，然后让curA移动到，和curB 末尾对齐的位置
        // 此时我们就可以比较curA和curB是否相同，如果不相同，同时向后移动curA和curB，如果遇到curA == curB，则找到交点。
        // 否则循环退出返回空指针。
        ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
            ListNode* curA = headA;
            ListNode* curB = headB;
            int lenA = 0, lenB = 0;
            while (curA != nullptr) { // 求链表A的长度
                lenA++;
                curA = curA->next;
            }
            while (curB != nullptr) { // 求链表B的长度
                lenB++;
                curB = curB->next;
            }
            curA = headA;
            curB = headB;
            // 让curA为最长链表的头，lenA为其长度
            if (lenB > lenA) {
                swap (lenA, lenB);
                swap (curA, curB);
            }
            // 求长度差
            int gap = lenA - lenB;
            // 让curA和curB在同一起点上（末尾位置对齐）
            while (gap--) {
                curA = curA->next;
            }
            // 遍历curA 和 curB，遇到相同则直接返回
            while (curA != nullptr) {
                if (curA == curB) {
                    return curA;
                }
                curA = curA->next;
                curB = curB->next;
            }
            return nullptr;
        }
        // 时间复杂度：O(m+n)，其中 m 和 n 是分别是链表 headA和 headB 的长度。两个指针同时遍历两个链表，每个指针遍历两个链表各一次。
        // 空间复杂度：O(1)。
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 环形链表II，medium，Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_142() {
    cout << endl << "leetcode_142" << endl;    
    // 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    // 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
    // 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
    // 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
    // 不允许修改 链表。
    // 输入: head = [3,2,0,-4], pos = 1
    // 输出: 返回索引为 1 的链表节点
    // Carl: https://www.programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html
    // leetcode: https://leetcode.cn/problems/linked-list-cycle-ii/description/

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：双指针法
        // 可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，
        // slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
        // 假设从头结点到环形入口节点 的节点数为x。 环形入口节点到 fast指针与slow指针相遇节点 节点数为y。 
        // 从相遇节点 再到环形入口节点节点数为 z。 
        // 那么相遇时： slow指针走过的节点数为: x + y， fast指针走过的节点数：x + y + n (y + z)，
        // n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。
        // 因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：
        // (x + y) * 2 = x + y + n (y + z)
        // 两边消掉一个（x+y）: x + y = n (y + z)
        // 整理公式之后为如下公式：x = (n - 1) (y + z) + z
        // 这就意味着，从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 
        // 那么当这两个指针相遇的时候就是 环形入口的节点。
        ListNode* detectCycle1(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    ListNode* index1 = fast;
                    ListNode* index2 = head;
                    while (index1 != index2) {
                        index1 = index1->next;
                        index2 = index2->next;
                    }
                    return index1;  // index1 = index2，返回任意一个
                }
            }
            return nullptr;
            
        }
        // 时间复杂度：O(n)，快慢指针相遇前，指针走的次数小于链表长度，快慢指针相遇后，
        //     两个index指针走的次数也小于链表长度，总体为走的次数小于 2n
        // 空间复杂度：O(1)。

        // 方法二：哈希法
        // 我们遍历链表中的每个节点，并将它记录下来；
        // 一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。
        ListNode* detectCycle2(ListNode* head) {
            unordered_set<ListNode*> visited;
            while (head != nullptr) {
                if (visited.count(head)) {
                    return head;
                }
                visited.insert(head);
                head = head->next;
            }
            return nullptr;
        }
        // 时间复杂度：O(n)，其中 N 为链表中节点的数目。我们恰好需要访问链表中的每一个节点。
        // 空间复杂度：O(n)，其中 N 为链表中节点的数目。我们需要将链表中的每个节点都保存在哈希表当中。
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 回文链表, simple, Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_234() {
    cout << endl << "leetcode_234" << endl;   
    // 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
    // 输入：head = [1,2,2,1]
    // 输出：true
    // Carl: https://www.programmercarl.com/0234.%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
    // leetcode: https://leetcode.cn/problems/palindrome-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：数组哈希法（不推荐，如果节点数量过大，数组空间过大）
        // 把链表装成数组，然后再判断是否回文
        // 先求出链表长度，然后给定vector的初始长度，这样避免vector每次添加节点重新开辟空间
        bool isPalindrome1(ListNode* head) {
            ListNode* cur  = head;
            int length = 0;
            while (cur) {
                length++;
                cur = cur->next;
            }
            vector<int> vec(length, 0); // 给定vector的初始长度，这样避免vector每次添加节点重新开辟空间
            cur = head;
            int index = 0;
            while (cur) {
                vec[index++] = cur->val;
                cur = cur->next;
            }
            // 比较数组回文
            for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
                if (vec[i] != vec[j]) return false;
            }
            return true;
        }
        // 时间复杂度：O(2.5n)，n为链表的长度，获取长度为n，更新index为n，判断回文0.5n
        // 空间复杂度：O(n)，n为链表的长度

        // 方法二：反转后半部分链表
        // 用快慢指针，快指针有两步，慢指针走一步，快指针遇到终止位置时，慢指针就在链表中间位置
        // 同时用pre记录慢指针指向节点的前一个节点，用来分割链表
        // 将链表分为前后均等两部分，如果链表长度是奇数，那么后半部分多一个节点
        // 将后半部分反转 ，得cur2，前半部分为cur1
        // 按照cur1的长度，一次比较cur1和cur2的节点数值
        bool isPalindrome2(ListNode* head) {
            if (head == nullptr || head->next == nullptr) return true;
            ListNode* slow = head; // 慢指针，找到链表中间分位置，作为分割
            ListNode* fast = head;
            ListNode* pre = head; // 记录慢指针的前一个节点，用来分割链表
            while (fast && fast->next) {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            pre->next = nullptr; // 分割链表

            ListNode* cur1 = head;  // 前半部分
            ListNode* cur2 = reverseList(slow); // 反转后半部分，总链表长度如果是奇数，cur2比cur1多一个节点

            // 开始两个链表的比较
            while (cur1) {
                if (cur1->val != cur2->val) return false;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return true;
        }
        // 反转链表
        ListNode* reverseList(ListNode* head) {
            ListNode* temp; // 保存cur的下一个节点
            ListNode* cur = head;
            ListNode* pre = nullptr;
            while(cur) {
                temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
                cur->next = pre; // 翻转操作
                // 更新pre 和 cur指针
                pre = cur;
                cur = temp;
            }
            return pre;
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)
        // 避免使用 O(n) 额外空间的方法就是改变输入。
        // 我们可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。
        // 比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，
        // 但是使用该函数的人通常不希望链表结构被更改。
        // 该方法虽然可以将空间复杂度降到 O(1)，但是在并发环境下，该方法也有缺点。
        // 在并发环境下，函数运行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改。


        // 方法三：递归
        // 时间复杂度：O(n)
        // 空间复杂度：O(n)
        // 这种方法不仅使用了 O(n) 的空间，且比第一种方法更差，因为在许多语言中，
        // 堆栈帧的开销很大（如 Python），并且最大的运行时堆栈深度为 1000
        // （可以增加，但是有可能导致底层解释程序内存出错）。
        // 为每个节点创建堆栈帧极大的限制了算法能够处理的最大链表大小。
    };

    cout << "please test the function in leetcode" << endl; 
}


///////////////////////////////////////////////////////////////////////////////
// 环形链表, simple, Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_141() {
    cout << endl << "leetcode_141" << endl;    
    // 给你一个链表的头节点 head ，判断链表中是否有环。
    // 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
    // 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
    // 注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
    // 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
    // 输入: head = [3,2,0,-4], pos = 1
    // 输出: true
    // leetcode: https://leetcode.cn/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-100-liked

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：双指针法
        // 具体分析过程见142
        bool hasCycle1(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {return false;}
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (slow != fast) {
                if (fast == nullptr || fast->next == nullptr) {return false;}
                fast = fast->next->next;
                slow = slow->next;
            }
            return true;
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)

        // 方法二：哈希法
        // 具体分析过程见142
        bool hasCycle2(ListNode* head) {
            unordered_set<ListNode*> visited;
            while (head != nullptr) {
                if (visited.count(head)) {
                    return true;
                }
                visited.insert(head);
                head = head->next;
            }
            return false;
        }
        // 时间复杂度：O(n)，其中 N 为链表中节点的数目。
        // 空间复杂度：O(n)
    };

    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 合并两个有序链表, simple, Hot100, Classic150
///////////////////////////////////////////////////////////////////////////////
void leetcode_21() {
    cout << endl << "leetcode_21" << endl;    
    // 将两个升序链表合并为一个新的 升序 链表并返回。
    // 新链表是通过拼接给定的两个链表的所有节点组成的。
    // 输入: l1 = [1,2,4], l2 = [1,3,4]
    // 输出：[1,1,2,3,4,4]
    // leetcode: https://leetcode.cn/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-100-liked

    class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        // 方法一：迭代法
        // 当 l1 和 l2 都不是空链表时，判断 l1 和 l2 哪一个链表的头节点的值更小，
        // 将较小值的节点添加到结果里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位。
        // 首先，我们设定一个哨兵节点 prehead ，这可以在最后让我们比较容易地返回合并后的链表。
        // 我们维护一个 prev 指针，我们需要做的是调整它的 next 指针。
        // 然后，我们重复以下过程，直到 l1 或者 l2 指向了 null
        ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
            ListNode* dummyHead = new ListNode(-1);
            ListNode* prev = dummyHead;
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val < list2->val) {
                    prev->next = list1;
                    list1 = list1->next;
                } else {
                    prev->next = list2;
                    list2 = list2->next;
                }
                prev = prev->next;
            }
            // 合并后 list1 和 list2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
            prev->next = list1 == nullptr ? list2 : list1;
            return dummyHead->next;            
        }
        // 时间复杂度：O(m+n)
        // 空间复杂度：O(1)

        // 方法二：递归法
        // 具体分析过程见142
        ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) {
                return list2;
            } else if (list2 == nullptr) {
                return list1;
            } else if (list1->val < list2->val) {
                list1->next = mergeTwoLists2(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoLists2(list1, list2->next);
                return list2;
            }
        }
        // 时间复杂度：O(m+n)
        // 空间复杂度：O(m+n)
    };

    cout << "please test the function in leetcode" << endl;
}


