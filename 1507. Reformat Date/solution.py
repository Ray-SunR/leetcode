class Solution:
    def reformatDate(self, date: str) -> str:
        splitted = date.split(" ")
        day, month, year = splitted[0], splitted[1], splitted[2]
        day = day[:-2]
        if len(day) == 1:
            day = "0" + day
        months = {
            "Jan": "01",
            "Feb": "02",
            "Mar": "03",
            "Apr": "04",
            "May": "05",
            "Jun": "06",
            "Jul": "07",
            "Aug": "08",
            "Sep": "09",
            "Oct": "10",
            "Nov": "11",
            "Dec": "12",
        }
        month = months[month]

        return "{}-{}-{}".format(year, month, day)