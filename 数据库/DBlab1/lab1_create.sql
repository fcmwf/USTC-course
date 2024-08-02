-- Active: 1712764934724@@127.0.0.1@3306@library
CREATE DATABASE IF NOT EXISTS Library;
USE library;
DROP TABLE IF EXISTS Book;
DROP TABLE IF EXISTS Reader;
DROP TABLE IF EXISTS Borrow;
CREATE TABLE Book (
    ID      CHAR(8),
    name    VARCHAR(10),
    author  VARCHAR(10),
    price   FLOAT,
    status  INT DEFAULT 0,
    times   INT DEFAULT 0,
    Constraint PK_Book  PRIMARY KEY (ID)
);
CREATE TABLE Reader (
    ID      CHAR(8),
    name    VARCHAR(10),
    age     INT,
    address VARCHAR(20),
    Constraint PK_Reader PRIMARY KEY (ID)
);
CREATE TABLE Borrow (
    book_ID     CHAR(8),
    Reader_ID   CHAR(8),
    Borrow_Date DATE,
    Return_Date DATE,
    Constraint PK_Borrow PRIMARY KEY (book_ID , Reader_ID),
    Constraint FK_Borrow_bookID     FOREIGN KEY (book_ID)   REFERENCES Book(ID),
    Constraint FK_Borrow_readerID   FOREIGN KEY (Reader_ID) REFERENCES Reader(ID)
);

 