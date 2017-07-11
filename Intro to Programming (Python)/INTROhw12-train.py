# Gurumeher Sawhney
# CS1114 HW 12

def main():
    seenDone = False
    while seenDone == False:
        line = input("Please enter a train line or 'done' to stop: ")
        stops = ""
        if line == "done":
            seenDone = True
        else:
            in_file = open("train stop data-Windows.csv","r")
            header = in_file.readline()
            in_file.readline()
            for curr_line in in_file:
                curr_line = curr_line.strip()
                curr_list = curr_line.split(',')
                #Finding the train line
                train = curr_list[0]
                train_line =  train[0]
                #Using my empty string to add all the stops that have
                #the same trainline
                if train_line == line:
                    stops += curr_list[2]+', '  
                for index in range(0,5):
                    in_file.readline()
            print(line,"line:",stops)
            print()
main()
        
