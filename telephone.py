class TelephoneBook:
    def __init__(self, name, tel_no):
        self.name = name
        self.tel_no = tel_no

def Insertion_QuadProbing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashValue = t % 10
        j = 0
        while hashtable[hashValue] is not None:
            if hashtable[hashValue].name == n:
                print(f"Updating the telephone number for {n}")
                hashtable[hashValue].tel_no = t
                break
            j += 1
            hashValue = (hashValue + (j * j)) % 10
        if hashtable[hashValue] is None:
            hashtable[hashValue] = TelephoneBook(n, t)
    return hashtable

def Insertion_DoubleHashing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashvalue = t % 9
        second_hash = 7 - (t % 7)
        j = 0
        while hashtable[hashvalue] is not None:
            if hashtable[hashvalue].name == n:
                print(f"Updating the telephone number for {n}")
                hashtable[hashvalue].tel_no = t
                break
            j += 1
            hashvalue = (hashvalue + j * second_hash) % 10
        if hashtable[hashvalue] is None:
            hashtable[hashvalue] = TelephoneBook(n, t)
    return hashtable

def Display_QP(hash1):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash1):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

def Display_DH(hash2):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash2):
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

def Search(hash1, hash2):
    n = input("Enter name to search: ")
    found = False
    for obj in hash1:
        if obj is not None and obj.name == n:
            print("\nFound in Hashtable-1!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{hash1.index(obj)}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            found = True
            break
    for obj in hash2:
        if obj is not None and obj.name == n:
            print("\nFound in Hashtable-2!")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{hash2.index(obj)}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            found = True
            break
    if not found:
        print("\nNot found!!!\n")

def main():
    hash1 = [None for _ in range(10)]
    hash2 = [None for _ in range(10)]
    while True:
        print("\t1.Insert Value")
        print("\t2.Display")
        print("\t3.Search")
        print("\t4.Exit")
        try:
            ch = int(input("Enter choice: "))
            if ch == 1:
                print("\nSelect collision method-")
                print("\t1.Quadratic Probing")
                print("\t2.Double Hashing")
                c = int(input("Enter choice: "))
                if c == 1:
                    hash1 = Insertion_QuadProbing()
                elif c == 2:
                    hash2 = Insertion_DoubleHashing()
                else:
                    print("! Invalid choice. Please enter 1 or 2.")
            elif ch == 2:
                print("\t1.Display QP")
                print("\t2.Display DH")
                c1 = int(input("Enter choice: "))
                if c1 == 1:
                    Display_QP(hash1)
                elif c1 == 2:
                    Display_DH(hash2)
                else:
                    print("! Invalid choice. Please enter 1 or 2.")
            elif ch == 3:
                Search(hash1, hash2)
            elif ch == 4:
                print("Exiting...")
                break
            else:
                print("! Invalid choice. Please enter a valid option.")
        except ValueError:
            print("! Invalid input. Please enter a valid number.")

if __name__ == "__main__":
    main()
