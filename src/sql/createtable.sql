CREATE TABLE Client
(idClient INT PRIMARY KEY (idClient),
NomReferent VARCHAR(30),
PrenomReferent VARCHAR(30),
Societe VARCHAR(30),
Adresse VARCHAR(50),
CodePostal INT,
Ville VARCHAR(30),
Mail VARCHAR(30),
TelephonePort INT,
TelephoneFixe INT,
Fax INT);

CREATE TABLE Project
(idProject INT PRIMARY KEY (idProject),
Nom VARCHAR2(30),
Description TEXT,
TarifJournalier INT,
idClient INT,
FOREIGN KEY (idClient) REFERENCES Client (idClient));

CREATE TABLE Facturation
(idFacturation INT PRIMARY KEY (idFacturation),
Titre VARCHAR(20),
numero INT,
Type BOOLEAN,
Date DATE);

CREATE TABLE Prestation
(idPrestation INT PRIMARY KEY (idPrestation),
Description TEXT,
nbDays INT,
CONSTRAINT pk_prestation );

CREATE TABLE FacturationProject
(idProject INT,
idFacturation INT,
idPrestation INT,
FOREIGN KEY (idProject) REFERENCES Project (idProject),
FOREIGN KEY (idFacturation) REFERENCES Facturation (idFacturation),
FOREIGN KEY (idPrestation) REFERENCES Prestation (idPrestation));

CREATE TABLE Users
(idUser INT PRIMARY KEY (idUser),
Nom VARCHAR(30),
Prenom VARCHAR(30),
Organisation VARCHAR(30),
Titre VARCHAR(20),
Adresse VARCHAR(50),
CodePostal INT,
Ville VARCHAR(30),
Mail VARCHAR(30),
TelephonePort INT,
TelephoneFixe INT,
NoSiret INT);
