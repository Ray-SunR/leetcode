lass Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        changes = {}
        for bill in bills:
            # print(bill)
            if bill == 5:
                changes[5] = changes.get(5, 0) + 1
            elif bill == 10:
                if changes.get(5, 0) == 0:
                    print(changes)
                    return False
                changes[5] -= 1
                changes[10] = changes.get(10, 0) + 1
            else:
                if changes.get(5, 0) >= 1 and changes.get(10, 0) >= 1:
                    #$10, $5
                    changes[10] -= 1
                    changes[5] -= 1
                    changes[20] = changes.get(20, 0) + 1
                    continue
                elif changes.get(5, 0) >= 3:
                    # $5,$5,$5
                    changes[5] -= 3
                    changes[20] = changes.get(20, 0) + 1
                else:
                    # print(changes)
                    return False
        return True
            
