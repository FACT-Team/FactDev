CREATE TABLE Client
(idClient INT,
NomReferent VARCHAR(30),
PrenomReferent VARCHAR(30),
Societe VARCHAR(30),
Adresse VARCHAR(50),
CodePostal INT,
Ville VARCHAR(30),
Mail VARCHAR(30),
TelephonePort INT,
TelephoneFixe INT,
Fax INT,
CONSTRAINT pk_client PRIMARY KEY (idClient));

CREATE TABLE Project
(idProject INT
Nom VARCHAR2(30),
Description TEXT,
TarifJournalier INT,
idClient INT,
CONSTRAINT pk_project PRIMARY KEY (idProject),
CONSTRAINT fk_project FOREIGN KEY (idClient)
REFERENCES Client (idClient));

CREATE TABLE Facturation
(idFacturation INT,
Titre VARCHAR(20),
numero INT,
Type BOOLEAN,
Date DATE,
CONSTRAINT pk_facturation PRIMARY KEY (idFacturation));

CREATE TABLE Prestation
(idPrestation INT,
Description TEXT,
nbDays INT,
CONSTRAINT pk_prestation PRIMARY KEY (idPrestation));

CREATE TABLE FacturationProject
(idProject INT,
idFacturation INT,
idPrestation INT,
CONSTRAINT fk_factProjectP FOREIGN KEY (idProject)
REFERENCES Project (idProject),
CONSTRAINT fk_factProjectF FOREIGN KEY (idFacturation)
REFERENCES Facturation (idFacturation),
CONSTRAINT fk_factProjectPr FOREIGN KEY (idPrestation)
REFERENCES Prestation (idPrestation));

CREATE TABLE Users
(idUser INT,
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
NoSiret INT,
CONSTRAINT pk_user PRIMARY KEY (idUser));
