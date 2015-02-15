delete from customer
where idCustomer in
(SELECT idCustomer FROM Customer
WHERE idCustomer not in (SELECT idCustomer FROM Project));
<<<<<<< HEAD


=======
>>>>>>> 9411e1e8f6d344013baa652b221bfc4238d9b28b
