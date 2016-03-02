
hour, minutes = map(int, raw_input().split (':'));
time_passed = map(int, raw_input().split())[0];

def format_hour (hour):
    if (hour < 10):
        return '0' + str(hour);
    else:
        return str(hour);

def format_minutes (minutes):
    if (minutes < 10):
        return '0' + str(minutes);
    else:
        return str(minutes);

while True:
    if (time_passed == 0):
        break;
    
    if time_passed >= 60:
        hour = (hour + 1) % 24;
        time_passed -= 60;
    else:
        if (minutes + time_passed >= 60):
            hour = (hour + 1) % 24;
        minutes = (minutes + time_passed) % 60;
        time_passed = 0;

print format_hour(hour) + ':' + format_minutes(minutes);
