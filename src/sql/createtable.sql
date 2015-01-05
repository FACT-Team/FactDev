CREATE TABLE Customer
(
    idCustomer INT PRIMARY KEY,
    firstnameReferent VARCHAR(64),
    lastnameReferent VARCHAR(64),
    company VARCHAR(64),
    address VARCHAR(128),
    postalCode VARCHAR(8),
    city VARCHAR(64),
    country VARCHAR(64),
    email VARCHAR(64),
    mobilePhone VARCHAR(16),
    phone VARCHAR(16),
    fax VARCHAR(16)
);

CREATE TABLE Project
(
    idProject INT PRIMARY KEY,
    name VARCHAR(64),
    description TEXT,
    dailyRate DOUBLE,
    idCustomer INT,
    FOREIGN KEY (idCustomer) REFERENCES Customer (idCustomer)
);

CREATE TABLE Billing
(
    idBilling INT PRIMARY KEY,
    title VARCHAR(64),
    number INT,
    isBilling BOOLEAN,
    date DATETIME
);

CREATE TABLE Contributory
(
    idContributory INT PRIMARY KEY,
    description TEXT,
    nbDays INT
);

CREATE TABLE BillingProject
(
    idProject INT,
    idBilling INT,
    idContributory INT,
    PRIMARY KEY (idProject, idBilling, idContributory),
    FOREIGN KEY (idProject) REFERENCES Project (idProject),
    FOREIGN KEY (idBilling) REFERENCES Billing (idBilling),
    FOREIGN KEY (idContributory) REFERENCES Contributory (idContributory)
);

CREATE TABLE User
(
    idUser INT PRIMARY KEY,
    firstname VARCHAR(64),
    lastname VARCHAR(64),
    company VARCHAR(64),
    title VARCHAR(64),
    address VARCHAR(128),
    postalCode VARCHAR(16),
    city VARCHAR(64),
    email VARCHAR(64),
    mobilePhone VARCHAR(16),
    phone VARCHAR(16),
    NoSiret INT
);
