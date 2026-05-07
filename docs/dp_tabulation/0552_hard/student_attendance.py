
def count_possibilities(record_len: int) -> int:  # LeetCode Q.552.
    # Possible ends: "P", "L", "LL". Base case: record len = 1.
    no_abs_table = {"p": 1, "l": 1, "ll": 0}

    # Possible ends: "P", "L", "LL", "A". Base case: record len = 1.
    one_abs_table = {"p": 0, "l": 0, "ll": 0, "a": 1}

    # Help each day's tables update values.
    new_no_abs_table, new_one_abs_table = dict(), dict()

    modulo = 10 ** 9 + 7

    for _ in range(2, record_len + 1):
        
        no_abs_sum = sum(no_abs_table.values()) % modulo

        new_no_abs_table["p"] = no_abs_sum  # No.1: all 0 absence ends are now "P".

        new_no_abs_table["l"] = no_abs_table["p"]  # No.2: 0 absence end "P" => "L".
        new_no_abs_table["ll"] = no_abs_table["l"]  # No.3: 0 absence end "L" => "LL".

        one_abs_sum = sum(one_abs_table.values()) % modulo

        new_one_abs_table["p"] = one_abs_sum  # No.4: all 1 absence ends are now "P".

        # No.5: 1 absence end from "P" or "A" to "L".
        new_one_abs_table["l"] = (one_abs_table["p"] + one_abs_table["a"]) % modulo

        new_one_abs_table["ll"] = one_abs_table["l"]  # No.6: 1 absence end "l" => "ll".

        new_one_abs_table["a"] = no_abs_sum  # No.7: from 0 to 1 absence.

        no_abs_table.update(new_no_abs_table)
        one_abs_table.update(new_one_abs_table)
        
        new_no_abs_table.clear()  # Reset for next day's usage.
        new_one_abs_table.clear()
        
    valid_combinations = sum(no_abs_table.values()) + sum(one_abs_table.values())
    return valid_combinations % modulo
