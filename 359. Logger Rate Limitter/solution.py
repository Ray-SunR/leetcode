class Logger:
    def __init__(self):
        self.d = {}
    """
    @param timestamp: Timestamp
    @param message: Message
    @return: Whether the log can be printed
    """
    def could_print_message(self, timestamp: int, message: str) -> bool:
        if message not in self.d:
            self.d[message] = timestamp
            return True
        elif timestamp - self.d[message] >= 10:
            self.d[message] = timestamp
            return True
        return False
        
        
