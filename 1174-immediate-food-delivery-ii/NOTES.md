we need first order from each customer_id so use partition by
then count number of customer with order=pref_order using sum( switch ) .