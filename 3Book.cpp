class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Dictionary:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        for pair in self.table[index]:
            if pair.key == key:
                pair.value = value
                return
        self.table[index].append(Node(key, value))

    def find(self, key):
        index = self._hash(key)
        for pair in self.table[index]:
            if pair.key == key:
                return pair.value
        return None

    def delete(self, key):
        index = self._hash(key)
        for i, pair in enumerate(self.table[index]):
            if pair.key == key:
                del self.table[index][i]
                return True
        return False

    def display(self):
        for i, bucket in enumerate(self.table):
            print(f"Index {i}:", end=" ")
            for pair in bucket:
                print(f"({pair.key}: {pair.value})", end=" -> ")
            print("None")

def main():
    d = Dictionary()
    while True:
        print("\n1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit")
        choice = input("Enter choice: ")
        if choice == "1":
            key = input("Enter key: ")
            value = input("Enter value: ")
            d.insert(key, value)
        elif choice == "2":
            key = input("Enter key to find: ")
            result = d.find(key)
            if result is not None:
                print(f"Found: {key} -> {result}")
            else:
                print("Key not found")
        elif choice == "3":
            key = input("Enter key to delete: ")
            if d.delete(key):
                print("Key deleted")
            else:
                print("Key not found")
        elif choice == "4":
            d.display()
        elif choice == "5":
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
