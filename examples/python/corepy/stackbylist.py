#!/usr/bin/python

stack = []

def push_item():
    stack.append(raw_input("Enter a string: ").strip())

def pop_item():
    if len(stack) == 0:
        print("Can't pop from an empty stack!")
    else:
        print 'Removed [', stack.pop(), ']'

def print_items():
    print(stack)

COMMANDS = {'u': push_item, 'o': pop_item, 'v': print_items}

def show_menu():
    menu = """
    p(U)sh
    p(O)p
    (V)iew
    (Q)uit

    Enter your choice: """
    
    while True:
        try:
            choice = raw_input(menu).strip()[0].lower()
        except (EOFError, KeyboardInterrupt, IndexError):
            choice = 'q'

        print("\nYou selected: [%s]" % choice)

        if choice not in "uovq":
            print("Invalid option, try again.")
        else:
            return choice;

def main():
    while True:
       choice = show_menu() 
       if choice == 'q':
           break;
       COMMANDS[choice]()
       
if __name__ == "__main__":
    main()
