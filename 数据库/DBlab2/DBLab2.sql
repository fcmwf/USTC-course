/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2024/5/6 22:02:05                            */
/*==============================================================*/
USE bank

alter table Account 
   drop foreign key FK_ACCOUNT_开户_BANK;

alter table Client 
   drop foreign key FK_CLIENT_拥有_LOAN;

alter table ContactPerson 
   drop foreign key FK_CONTACTP_依赖_CLIENT;

alter table Credit 
   drop foreign key FK_CREDIT_继承_ACCOUNT;

alter table Loan 
   drop foreign key FK_LOAN_发放_BANK;

alter table Loan_Status 
   drop foreign key FK_LOAN_STA_逐次支付_LOAN;

alter table Saving 
   drop foreign key FK_SAVING_继承2_ACCOUNT;

alter table staff 
   drop foreign key FK_STAFF_START_TIM_BANK;

alter table staff 
   drop foreign key FK_STAFF_属于_DEPARTME;

alter table 拥有 
   drop foreign key FK_拥有_拥有2_CLIENT;

alter table 拥有 
   drop foreign key FK_拥有_拥有3_ACCOUNT;

alter table 负责 
   drop foreign key FK_负责_负责_STAFF;

alter table 负责 
   drop foreign key FK_负责_负责2_CLIENT;


alter table Account 
   drop foreign key FK_ACCOUNT_开户_BANK;

drop table if exists Account;


alter table Client 
   drop foreign key FK_CLIENT_拥有_LOAN;

drop table if exists Client;


alter table ContactPerson 
   drop foreign key FK_CONTACTP_依赖_CLIENT;

drop table if exists ContactPerson;


alter table Credit 
   drop foreign key FK_CREDIT_继承_ACCOUNT;

drop table if exists Credit;

drop table if exists Department;


alter table Loan 
   drop foreign key FK_LOAN_发放_BANK;

drop table if exists Loan;


alter table Loan_Status 
   drop foreign key FK_LOAN_STA_逐次支付_LOAN;

drop table if exists Loan_Status;


alter table Saving 
   drop foreign key FK_SAVING_继承2_ACCOUNT;

drop table if exists Saving;

drop table if exists bank;


alter table staff 
   drop foreign key FK_STAFF_START_TIM_BANK;

alter table staff 
   drop foreign key FK_STAFF_属于_DEPARTME;

drop table if exists staff;


alter table 拥有 
   drop foreign key FK_拥有_拥有2_CLIENT;

alter table 拥有 
   drop foreign key FK_拥有_拥有3_ACCOUNT;

drop table if exists 拥有;


alter table 负责 
   drop foreign key FK_负责_负责_STAFF;

alter table 负责 
   drop foreign key FK_负责_负责2_CLIENT;

drop table if exists 负责;

/*==============================================================*/
/* Table: Account                                               */
/*==============================================================*/
create table Account
(
   AccountID            numeric(8,0) not null  comment '',
   Name                 text  comment '',
   Money                float(8,2) not null  comment '',
   primary key (AccountID)
);

/*==============================================================*/
/* Table: Client                                                */
/*==============================================================*/
create table Client
(
   ID                   numeric(18,0) not null  comment '',
   Loan_ID              numeric(8,0)  comment '',
   ClientName           text  comment '',
   Tel                  numeric(11,0)  comment '',
   Address              text  comment '',
   primary key (ID)
);

/*==============================================================*/
/* Table: ContactPerson                                         */
/*==============================================================*/
create table ContactPerson
(
   ID                   numeric(18,0) not null  comment '',
   ContactPersonName    text  comment '',
   Tel                  numeric(11,0)  comment '',
   Email                varchar(20)  comment '',
   ContactType          text  comment '',
   primary key (ID)
);

/*==============================================================*/
/* Table: Credit                                                */
/*==============================================================*/
create table Credit
(
   AccountID            numeric(8,0) not null  comment '',
   "Limit"              float(8,2)  comment '',
   primary key (AccountID)
);

/*==============================================================*/
/* Table: Department                                            */
/*==============================================================*/
create table Department
(
   Department_ID        numeric(8,0) not null  comment '',
   Depart_Name          text  comment '',
   Depart_Type          text  comment '',
   Manager_ID           numeric(8,0)  comment '',
   primary key (Department_ID)
);

/*==============================================================*/
/* Table: Loan                                                  */
/*==============================================================*/
create table Loan
(
   Loan_ID              numeric(8,0) not null  comment '',
   Name                 text  comment '',
   Total_Money          float(8,2)  comment '',
   primary key (Loan_ID)
);

/*==============================================================*/
/* Table: Loan_Status                                           */
/*==============================================================*/
create table Loan_Status
(
   Loan_ID              numeric(8,0) not null  comment '',
   Pay_Date             date  comment '',
   Pay_Money            float(8,2)  comment '',
   primary key (Loan_ID)
);

/*==============================================================*/
/* Table: Saving                                                */
/*==============================================================*/
create table Saving
(
   AccountID            numeric(8,0) not null  comment '',
   Rate                 float  comment '',
   principal_Type       bool  comment '',
   primary key (AccountID)
);

/*==============================================================*/
/* Table: bank                                                  */
/*==============================================================*/
create table bank
(
   Name                 text not null  comment '',
   City                 text  comment '',
   Asset                float(8,2)  comment '',
   primary key (Name)
);

/*==============================================================*/
/* Table: staff                                                 */
/*==============================================================*/
create table staff
(
   Job_number           numeric(8,0) not null  comment '',
   Department_ID        numeric(8,0)  comment '',
   Name                 text not null  comment '',
   Staff_name           text  comment '',
   Tel                  numeric(11,0)  comment '',
   Address              text  comment '',
   Department_number    numeric(8,0)  comment '',
   manager              bool  comment '',
   Start_Time           date  comment '',
   primary key (Job_number)
);

/*==============================================================*/
/* Table: 拥有                                                    */
/*==============================================================*/
create table 拥有
(
   ID                   numeric(18,0) not null  comment '',
   AccountID            numeric(8,0) not null  comment '',
   Recent_Date          date  comment '',
   primary key (ID, AccountID)
);

/*==============================================================*/
/* Table: 负责                                                    */
/*==============================================================*/
create table 负责
(
   Job_number           numeric(8,0) not null  comment '',
   ID                   numeric(18,0) not null  comment '',
   principal_Type       bool  comment '',
   primary key (Job_number, ID)
);

alter table Account add constraint FK_ACCOUNT_开户_BANK foreign key (Name)
      references bank (Name) on delete restrict on update restrict;

alter table Client add constraint FK_CLIENT_拥有_LOAN foreign key (Loan_ID)
      references Loan (Loan_ID) on delete restrict on update restrict;

alter table ContactPerson add constraint FK_CONTACTP_依赖_CLIENT foreign key (ID)
      references Client (ID) on delete restrict on update restrict;

alter table Credit add constraint FK_CREDIT_继承_ACCOUNT foreign key (AccountID)
      references Account (AccountID) on delete restrict on update restrict;

alter table Loan add constraint FK_LOAN_发放_BANK foreign key (Name)
      references bank (Name) on delete restrict on update restrict;

alter table Loan_Status add constraint FK_LOAN_STA_逐次支付_LOAN foreign key (Loan_ID)
      references Loan (Loan_ID) on delete restrict on update restrict;

alter table Saving add constraint FK_SAVING_继承2_ACCOUNT foreign key (AccountID)
      references Account (AccountID) on delete restrict on update restrict;

alter table staff add constraint FK_STAFF_START_TIM_BANK foreign key (Name)
      references bank (Name) on delete restrict on update restrict;

alter table staff add constraint FK_STAFF_属于_DEPARTME foreign key (Department_ID)
      references Department (Department_ID) on delete restrict on update restrict;

alter table 拥有 add constraint FK_拥有_拥有2_CLIENT foreign key (ID)
      references Client (ID) on delete restrict on update restrict;

alter table 拥有 add constraint FK_拥有_拥有3_ACCOUNT foreign key (AccountID)
      references Account (AccountID) on delete restrict on update restrict;

alter table 负责 add constraint FK_负责_负责_STAFF foreign key (Job_number)
      references staff (Job_number) on delete restrict on update restrict;

alter table 负责 add constraint FK_负责_负责2_CLIENT foreign key (ID)
      references Client (ID) on delete restrict on update restrict;

