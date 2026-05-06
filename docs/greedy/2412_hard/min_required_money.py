
def calculate_min_required_money(transactions: list[list[int]]) -> int:  # LeetCode Q.2412.
    total_abs_loss = 0

    losing_trade_max_cashback = -1
    winning_trade_max_cost = -1

    for cost, cashback in transactions:
        if cashback > cost:
            if cost > winning_trade_max_cost:
                winning_trade_max_cost = cost
            continue

        abs_loss = cost - cashback
        total_abs_loss += abs_loss
        
        if cashback > losing_trade_max_cashback:
            losing_trade_max_cashback = cashback
    
    min_required_money = total_abs_loss + losing_trade_max_cashback
    
    if winning_trade_max_cost == -1: return min_required_money

    if min_required_money < winning_trade_max_cost + total_abs_loss:
        min_required_money = winning_trade_max_cost + total_abs_loss

    return min_required_money
