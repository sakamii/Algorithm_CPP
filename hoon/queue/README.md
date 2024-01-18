# **Queue**

선입선출(First-in First-out, FIFO)

---

용어

- (1) Enqueue(push) : Queue에 원소 삽입 - **O(1)**
- (2) Dequeue(pop) : Queue에 원소 삭제 - **O(1)**
- (3) empty : Queue가 비어있으면 true를 반환. 아니라면 false - **O(1)**
- (4) size : Queue의 size 반환 - **O(1)**

---

장점

- 원소의 삽입과 삭제가 빠르다. C++의 경우 STL에서 제공하기 때문에 사용하면 된다.

단점

- 여전히 Search에는 **O(n)**의 시간복잡도가 걸린다.

---

응용

- (1) Deque(Double Ended Queue)
- (2) Priority Queue(Heap)
