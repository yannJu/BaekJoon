time = input()
m = 15
sHour = int(time[:2])
sMin = m + int((time[2:]))

if sMin >= 60:
    sMin -= 60
else:
    sHour -= 1
    if sHour < 0:
        sHour = 23

print(str(sHour) + " " + str(sMin))