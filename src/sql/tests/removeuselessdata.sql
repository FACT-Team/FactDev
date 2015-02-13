delete from customer
where idCustomer in
(SELECT idCustomer FROM Customer
WHERE idCustomer not in (SELECT idCustomer FROM Project));
