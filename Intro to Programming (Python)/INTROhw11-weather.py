'''

Gurumeher Sawhney
CS 1114
gs2605

This program worked with a large .csv file that contained various weather measurements for cities. It contained
functions to make the information easier to read and work with such as cleaning up the file and looking for
certain inputs. 
'''


# Part A
def clean_data(complete_weather_filename, cleaned_weather_filename):
    # Complete this function to clean the CSV.
    in_file = open(complete_weather_filename,"r")
    out_file = open(cleaned_weather_filename,"w")

    header = in_file.readline()
    line2 = in_file.readline()
    print("City,Date,High,Low,Precipitation ", file = out_file)
    # This reads the in.file and individually picks which columns to put in
    # the outfile
    for curr_line in in_file:
        curr_line = curr_line.strip()
        curr_list = curr_line.split(',')
        city = curr_list[0]
        date = curr_list[1]
        high = int(curr_list[2])
        low = int(curr_list[3])
        precip = (curr_list[8])
        if precip.isupper() == True:        
            precip = 0
        print(city,date,high,low,precip,sep = ',',file = out_file)
        in_file.readline()
  


# Part B
def f_to_c(f_temperature):
    new_c = (f_temperature - 32)*(5/9)
    return new_c

def in_to_cm(inches):
    new_cm = inches*2.54
    return new_cm

def convert_data_to_metric(imperial_weather_filename, metric_weather_filename):
    # Similar to clean_data() - read in the file and make a new file with metric values.
    in_file = open(imperial_weather_filename,"r")
    out_file = open(metric_weather_filename,"w")

    header = in_file.readline()
    print("City,Date,High,Low,Precipitation ", file = out_file)
    # The sorts out the high, low, and precipitatin and then changes their values using
    # the conversion functions above
    for curr_line in in_file:
        curr_line = curr_line.strip()
        curr_list = curr_line.split(',')
        city = curr_list[0]
        date = curr_list[1]
        high = int(curr_list[2])
        new_high = f_to_c(high)
        low = int(curr_list[3])
        new_low = f_to_c(low)
        precip = float(curr_list[4])
        new_precip = in_to_cm(precip)
        print(city,date,new_high,new_low,new_precip,sep = ',',file = out_file)

    in_file.close()
    out_file.close()

# Part C
def print_average_temps_per_month(city, weather_filename, unit_type):
    # prints average highs and lows in each month for the given city
    in_file = open(weather_filename,"r")
    header = in_file.readline()
    print("Average temperatures for",city,":")
    month_list = ["","January","February","March","April","May","June","July","August","September","October","November","December"]
    sum_of_highs = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    sum_of_lows = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    count = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    # This loop creates a sum of all the high and lows for each city and has a count function
    # to later create an average of the temperatures
    for curr_line in in_file:
        curr_line = curr_line.strip()
        curr_list = curr_line.split(',')
        if curr_list[0] == city:
            date = curr_list[1].split('/')
            month = int(date[0])
            hightemp = float(curr_list[2])
            sum_of_highs[month] += hightemp
            lowtemp = float(curr_list[3])
            sum_of_lows[month] += lowtemp
            count[month] += 1
    # This loop creates the average and then prints out the correct format
    for index in range(1,12+1):
        sum_of_highs[index] = sum_of_highs[index]/(count[index])
        sum_of_lows[index] = sum_of_lows[index]/(count[index])
        if unit_type == "imperial":
            print(month_list[index]+": "+str(sum_of_highs[index])+"F High, "+str(sum_of_lows[index])+"F Low")
        if unit_type == "metric":
            print(month_list[index]+": "+str(sum_of_highs[index])+"C High, "+str(sum_of_lows[index])+"C Low")


# Part D
# This programs is going to look for the record high of the years and year achieved for the city
# provided by the input and then display them
def print_record_high(city, weather_filename, unit_type):
    in_file = open(weather_filename,"r")
    header = in_file.readline()
    record_high = 0
    record_year = 0
    for curr_line in in_file:
        curr_line = curr_line.strip()
        curr_list = curr_line.split(',')
        # This holds the largest temperature while scanning through all
        # record high temperatures
        if curr_list[0] == city:
            date = curr_list[1].split('/')
            year = int(date[2])
            high = float(curr_list[2])
            if(high > record_high):
                record_high = high
                record_year = year
            
    if unit_type == "imperial":
        print("In",city,"the record high was "+str(record_high)+"F in year "+str(record_year))
    if unit_type == "metric":
        print("In",city,"the record high was "+str(record_high)+"C in year "+str(record_year))

def main():
    print ("Running Part A")
    clean_data("weather.csv", "weather in imperial.csv")
    
    print ("Running Part B")
    convert_data_to_metric("weather in imperial.csv", "weather in metric.csv")
    
    print ("Running Part C")
    print_average_temps_per_month("San Francisco", "weather in imperial.csv", "imperial")
    print_average_temps_per_month("New York", "weather in metric.csv", "metric")
    print_average_temps_per_month("San Jose", "weather in imperial.csv", "imperial")

    print ("Running Part D")
    print_record_high("San Francisco", "weather in imperial.csv", "imperial")
    print_record_high("New York", "weather in metric.csv", "metric")
    print_record_high("San Jose", "weather in imperial.csv", "imperial")

    
main()
