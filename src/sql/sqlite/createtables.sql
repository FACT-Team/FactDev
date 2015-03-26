CREATE TABLE Customer
(
    idCustomer INTEGER PRIMARY KEY AUTOINCREMENT,
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
    fax VARCHAR(16),
    complementAddress VARCHAR(128),
    website VARCHAR(128)
);

CREATE TABLE Project
(
    idProject INTEGER PRIMARY KEY AUTOINCREMENT,
    name VARCHAR(64),
    description TEXT,
    beginDate DATETIME,
    endDate DATETIME,
    dailyRate DOUBLE,
    idCustomer INTEGER,
    FOREIGN KEY (idCustomer) REFERENCES Customer (idCustomer)
);

CREATE TABLE Billing
(
    idBilling INTEGER PRIMARY KEY AUTOINCREMENT,
    title VARCHAR(64),
    description TEXT,
    number INTEGER,
    isBilling BOOLEAN,
    date DATETIME,
    isPaid BOOLEAN
);

CREATE TABLE Contributory
(
    idContributory INTEGER PRIMARY KEY AUTOINCREMENT,
    description TEXT,
    longdescription TEXT,
    quantity DOUBLE,
    unit INTEGER(2)
);

CREATE TABLE BillingProject
(
    idProject INTEGER,
    idBilling INTEGER,
    idContributory INTEGER,
    PRIMARY KEY (idProject, idBilling, idContributory),
    FOREIGN KEY (idProject) REFERENCES Project (idProject),
    FOREIGN KEY (idBilling) REFERENCES Billing (idBilling),
    FOREIGN KEY (idContributory) REFERENCES Contributory (idContributory)
);

CREATE TABLE BillingRate
(
    idBilling INTEGER,
    idProject INTEGER,
    hourlyRate DOUBLE,
    PRIMARY KEY(idBilling, idProject),
    FOREIGN KEY (idBilling) REFERENCES Billing(idBilling),
    FOREIGN KEY (idProject) REFERENCES Project(idProject)
);

CREATE TABLE User
(
    idUser INTEGER PRIMARY KEY AUTOINCREMENT,
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
    noSiret VARCHAR(16),
    workspaceName VARCHAR(64),
    workspacePath TEXT,
    pdflatexcommand VARCHAR(256),
    complementAddress VARCHAR(128),
    website VARCHAR(128)
);

CREATE INDEX I_PK_CUSTOMER ON Customer (idCustomer ASC, lastnameReferent);
CREATE INDEX I_PK_PROJECT ON Project (idProject, name);
CREATE INDEX I_PK_BILLING ON Billing (idBilling, title, number);
CREATE INDEX I_PK_CONTRIBUTORY ON Contributory (idContributory ASC);
CREATE INDEX I_PK_BILLINGPROJECT ON BillingProject (idProject, idBilling, idContributory);
INSERT INTO User(idUser) VALUES(1);
