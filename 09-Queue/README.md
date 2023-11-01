# 📚 Queue Data Structure

A queue is a fundamental data structure that follows the **FIFO (First-In-First-Out)** principle. It can be thought of as a linear collection of elements in which items are added to one end (rear) and removed from the other end (front).

## 🌱 Key Characteristics:

1. **Enqueue (Push):** Adding an element to the rear of the queue.
2. **Dequeue (Pop):** Removing an element from the front of the queue.
3. **Front:** The element at the front of the queue, which is the next to be dequeued.
4. **Rear:** The element at the rear of the queue, where new elements are enqueued.

## 🌱 Common Operations:

- **enqueue(item):** Adds an item to the rear of the queue.
- **dequeue():** Removes and returns the item at the front of the queue.
- **front():** Returns the item at the front of the queue without removing it.
- **rear():** Returns the item at the rear of the queue.
- **isEmpty():** Checks if the queue is empty.
- **size():** Returns the number of elements in the queue.

## 🌱 Use Cases:

1. **Breadth-First Search (BFS):** Queues are essential for traversing graphs in a level-by-level manner, such as in BFS.
2. **Task Scheduling:** When tasks or processes need to be executed in a specific order.
3. **Print Queue:** Managing print jobs in a printer's queue.
4. **Data Buffering:** Storing and processing data in the order it is received.
5. **Call Center Systems:** Managing customer service requests in the order they are received.

## 🌱 Implementation:

Queues can be implemented using various data structures, such as arrays or linked lists. The choice of implementation depends on the specific requirements of the application. Array-based implementations provide constant-time access to the front and rear, while linked list implementations allow dynamic resizing with minimal overhead.

📝 Queues are a versatile data structure with applications in a wide range of fields, making them an essential concept for any programmer to understand.
