delete from customer
where idCustomer in
(SELECT idCustomer FROM Customer
WHERE idCustomer not in (SELECT idCustomer FROM Project));

delete from billing
where idBilling IN
(select idBilling from billing where idBilling
not in (select idBilling from billingProject));

delete from contributory
where idCOntributory in
(select idContributory from contributory where idContributory
not in (select idContributory from billingProject));

delete from project
where idProject in
(select idProject from project where idProject
NOT in (select idProject from billingproject));
