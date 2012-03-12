#!/usr/bin/python

queue = []

def enqueue():
    queue.append(raw_input("Enter a string: ").strip())

def dequeue():
    if len(queue) == 0:
        print("Can't pop from an empty queue!")
    else:
        print "Removed [", queue.pop(0), "]"

def printqueue():
    print queue

COMMANDS = {'e': enqueue, 'd': dequeue, 'v': printqueue}

def showmenu():
    menu = """
    (E)nqueue
    (D)equeue
    (V)iew
    (Q)uit

    Enter choice: """

    while True:
        try:
            choice = raw_input(menu).strip()[0].lower()
        except (EOFError, KeyboardInterrupt, IndexError):
            choice = 'q'

        print("\nYou selected: [%s]" % choice)
        if choice not in "edvq":
            print("Invalid option.")
        else:
            return choice

def main():
    while True:
        choice = showmenu()
        if choice == 'q':
            break
        COMMANDS[choice]()

if __name__ == '__main__':
    main()
