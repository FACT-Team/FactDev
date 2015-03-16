delete from Customer where idCustomer not in (SELECT idCustomer FROM Project)
