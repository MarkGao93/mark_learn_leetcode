#include "common.h"
#include "linked_list.h"
// #include <string>
// #include <assert.h>
// #include <algorithm>
// #include <queue>
// #include <unordered_set>
// #include <unordered_map>
// using std::vector;
// using std::string;
// using std::unordered_set;
// using std::unordered_map;
// using std::pair;
// using std::sort;
// using std::swap;
// using std::reverse;





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

    // 给你一个单链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
    LinkedNode* removeElements(LinkedNode* head, int val) {
        bool method1 = true;
        bool method2 = false;
        bool method3 = false;
        // if (method1) {
        // 方法一（推荐）：设置一个虚拟头结点再进行移除节点操作
        LinkedNode * dummyHead = new LinkedNode (0);  // 设置一个虚拟头结点
        dummyHead->next = head;  // 将虚拟头结点指向head，这样方便后面做删除操作
        LinkedNode * cur = dummyHead;
        while (cur->next != nullptr) {  // while (cur->next)
            if (cur->next->val == val) {
                LinkedNode * tmp = cur->next;
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
        // }

        // 方法二：直接使用原来的链表来进行移除节点操作
        if (method2) {
        // 删除头结点
        while (head != nullptr && head->val == val) {  // 注意这里不是if
            LinkedNode * tmp = head;
            head = head->next;
            delete tmp;
            // tmp = nullptr;
        }

        // 删除非头结点
        LinkedNode * cur = head;
        while (cur != nullptr && cur->next!= nullptr) {
            if (cur->next->val == val) {
                LinkedNode * tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                // tmp = nullptr;
            } else {
                cur = cur->next;
            }
        }
        return head;        
        // 时间复杂度: O(n)
        // 空间复杂度: O(1)
        } 

        // 方法三：递归法
        // TODO: 递归实现
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



void leetcode_203();
void leetcode_707();
void leetcode_206();


int linked_list_main() {
    cout << endl << "linked_list_main" << endl << endl;

    // 我自己的链表类
    MyLinkedList myLinkedList;
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

    cout << "myLinkedList deleteAtIndex 1: " << endl;
    myLinkedList.deleteAtIndex(1);
    myLinkedList.printLinkedList();

    cout << "myLinkedList removeElements 6: " << endl;
    myLinkedList.removeAtVal(6);
    myLinkedList.printLinkedList();

    cout << "reverse myLinkedList: " << endl;
    myLinkedList.reverseList();
    myLinkedList.printLinkedList();




    // Carl Lessons
    leetcode_203();  // 移除链表元素，simple
    leetcode_707();  // 设计链表，medium
    leetcode_206();  // 反转链表，simple


    // leetcode_541();  // simple
    // leetcode_151();  // simple
    // leetcode_1();  // simple
    // leetcode_454();  // medium
    // leetcode_15();  // medium
    // leetcode_18();  // medium

    // leetcode_383();  // simple
    
    // leetcode_438();  // medium
    // leetcode_350();  // simple

    // LeetCode hot 100
    
    

    return 0;
}


void leetcode_203() {
    cout << endl << "leetcode_203" << endl;
    // 移除链表元素，simple
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

        ListNode* removeElements(ListNode* head, int val) {
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode* cur = dummyHead;
            while (cur->next != NULL) {
                if (cur->next->val == val) {
                    ListNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                }
                else {
                    cur = cur->next;
                }
            }
            head = dummyHead->next;
            delete dummyHead;
            return head;
        }
    };

    cout << "please test the function in leetcode" << endl;
}


void leetcode_707() {
    cout << endl << "leetcode_707" << endl;
    // 设计链表，medium
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


void leetcode_206() {
    cout << endl << "leetcode_206" << endl;
    // 反转链表，simple
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

        ListNode* reverseList(ListNode* head) {
            ListNode* temp;
            ListNode* cur = head;
            ListNode* pre = nullptr;
            while (cur) {
                temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            return pre;
        }
    };

    cout << "please test the function in leetcode" << endl;
}


