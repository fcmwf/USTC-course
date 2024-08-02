<center><font size = "5"><b>银行业务管理系统数据库设计

<center>PB21051012  刘祥辉

### 1、概念设计模式

#### 1.1 实体设计 

从介绍中可以看出**支行、职工、客户、账户、贷款、部门**具有明确的若干属性，所以可以设计为实体

- **支行**
  ![image-20240509175634585](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509175634585.png)

- **职工**
  ![image-20240509215929431](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509215929431.png)
- **账户**
  ![image-20240509180443489](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509180443489.png)

- **贷款**

![image-20240509180549987](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509180549987.png)

- **部门**
  ![image-20240509202359838](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509202359838.png)
- **联系人**
  <img src="C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509193448746.png" alt="image-20240509193448746" style="zoom:80%;" />

联系人的存在依赖于客户的存在，故这里联系人采用弱实体的设计

- **信用卡、储蓄**

  ![image-20240509201728458](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509201728458.png)

  从描述来看，这两个对象都有各自的属性：利率和透支额。且它们是“账户”的子集，所以将这两个对象设置为实体，并且继承“账户”。

- **支付情况**

  ![image-20240509201926037](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509201926037.png)

  贷款的支付不是一次性的，而“贷款”的主键贷款号无法标识逐次支付情况，如果将每次支付的日期和金额设计为“贷款”的属性，那么相对“贷款”的其他属性来说会产生冗余，造成空间的浪费，故将“支付情况”设计为一个单独的实体。由于“支付情况”这个实体对“贷款”产生依赖，所以必须将“支付情况”设计成若实体。

- **部门**

  ![image-20240509202158923](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509202158923.png)

  

#### 1.2 联系设计 

**a.根据需求：**

  支行：账户 （1 ：N）   每个支行可以开N个账户

  支行：贷款 （1 ：N）   每个支行可以发放N笔带块

  贷款：客户 （1 ：N）   一笔贷款可以被一 个或多个客户所共有

  部门:   职工（1 ：N）   每个员工只允许在一个部门内工作

**b.两个扩展的联系：**

信用卡、储蓄：账户               信用卡、储蓄继承账户的属性

贷款：支付情况 （1 ：N）     支付情况依赖贷款的属性

**c. 有属性的联系：**

支行：员工 （1 ：N，开始工作日期）   员工的开始工作时间是同支行联系的属性

客户：员工 （M ：N，负责人类型）  客户可能与不同员工发生联系，同样员工也可与不同客户发生联系

客户：账户 （M ：N，最近访问日期）客户可能有多个账户，同一账户也可能被多名客户拥有

#### 1.3 Power Designer 的 ER 图 

![image-20240509220013295](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509220013295.png)

### 2 概念模型到逻辑模型的转换 

#### 2.1 实体转换 

- **支行**

  ![image-20240509211452977](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211452977.png)

- **贷款**

  ![image-20240509211525322](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211525322.png)

- **职工**

  ![image-20240509215911671](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509215911671.png)

- **部门**
  ![image-20240509211612742](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211612742.png)

- **支付情况**
  ![image-20240509211636160](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211636160.png)

- **账户**
  ![image-20240509211655903](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211655903.png)

- **信用卡、储蓄**
  ![image-20240509211713030](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211713030.png)

- **客户**
  ![image-20240509211734042](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211734042.png)

- **联系人**
  ![image-20240509211754367](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509211754367.png)

#### 2.2 联系转换 

**a.根据需求：**

  支行：账户 （1 ：N）   使用外键来实现联系

  支行：贷款 （1 ：N）   使用外键来实现联系

  贷款：客户 （1 ：N）   使用外键来实现联系

  部门:   职工（1 ：N）   使用外键来实现联系

**b.两个扩展的联系：**

信用卡、储蓄：账户               继承账户的账户号属性

贷款：支付情况 （1 ：N）     使用客户的身份证号作为主码，并使用外键

**c. 有属性的联系：**

支行：员工 （1 ：N，开始工作日期）   员工的属性增加工作开始时间

客户：员工 （M ：N，负责人类型） 
![image-20240509213044411](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509213044411.png)

新增**负责**实体来实现M：N的联系

客户：账户 （M ：N，最近访问日期）
![image-20240509213131583](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509213131583.png)

新增**拥有**实体来实现M：N的联系

#### 2.3 最终的关系模式

支行(支行名称，城市，资产)

贷款（贷款号，支行名称，总额）

职工（工号，部门号，支行名称，姓名，电话，家庭住址，是否为经理，开始工作时间）

支付情况（贷款号，支付日期，支付金额）

账户（账户号，支行名称，余额，城市）

信用卡（账户号，透支额度）

储蓄（账户号，利率）

客户（身份证号，贷款号，姓名，电话，家庭住址）

联系人（身份证号，姓名，电话，Email，联系）

部门（部门号，部门名称，部门类型，部门经理工号）

拥有（身份证号，账户号，最近访问日期）

负责（工号，身份证号，负责人类型）

### 3 MySQL 数据库结构实现 

#### 3.1 Power Designer 的 PDM 图 

![image-20240509215954571](C:\Users\86139\AppData\Roaming\Typora\typora-user-images\image-20240509215954571.png)

#### 3.2 数据库表定义 //给出各个 Table 的定义

- 支行表(bank)

| 列名  | 中文含义 | 类型(长度)  | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键 |
| :---: | -------- | ----------- | --------------- | ---------------------- | -------- |
| Name  | 支行名称 | varchar(10) | 否              | 是                     | 否       |
| City  | 城市     | text        | 是              | 否                     | 否       |
| Asset | 资产     | float(8,2)  | 是              | 否                     | 否       |

- 职工表(staff)

|     列名      | 中文含义     | 类型(长度)    | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键                     |
| :-----------: | ------------ | ------------- | --------------- | ---------------------- | ---------------------------- |
|  Job_number   | 工号         | decimal(8,0)  | 否              | 是                     | 否                           |
| Department_ID | 部门号       | decimal(8,0)  | 是              | 否                     | 是(department.Department_ID) |
|     Name      | 支行名称     | varchar(10)   | 是              | 否                     | 是(bank.Name)                |
|  Staff_name   | 姓名         | text          | 是              | 否                     | 否                           |
|      Tel      | 电话         | decimal(11,0) | 是              | 否                     | 否                           |
|    Address    | 家庭住址     | text          | 是              | 否                     | 否                           |
|    manager    | 会否为经理   | tinyint(1)    | 是              | 否                     | 否                           |
|  Start_Time   | 开始工作时间 | data          | 是              | 否                     | 否                           |

- 部门表(department)

|     列名      | 中文含义   | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键 |
| :-----------: | ---------- | ------------ | --------------- | ---------------------- | -------- |
| Department_ID | 部门号     | decimal(8,0) | 否              | 是                     | 否       |
|  Depart_Name  | 部门名称   | text         | 是              | 否                     | 否       |
|  Depart_Type  | 部门类型   | text         | 是              | 否                     | 否       |
|  Manager_ID   | 部门经理号 | decimal(8,0) | 是              | 否                     | 否       |

- 贷款表(loan)

|    列名     | 中文含义 | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键                     |
| :---------: | -------- | ------------ | --------------- | ---------------------- | ---------------------------- |
|   Loan_ID   | 贷款号   | decimal(8,0) | 否              | 是                     | 否                           |
|    Name     | 支行名称 | varchar(10)  | 是              | 否                     | 是(department.Department_ID) |
| Total_Money | 总额     | float(8,2)   | 是              | 否                     | 否                           |

- 支付情况表(loan_status)

|   列名    | 中文含义 | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键         |
| :-------: | -------- | ------------ | --------------- | ---------------------- | ---------------- |
|  Loan_ID  | 贷款号   | decimal(8,0) | 否              | 是                     | 是(loan.Loan_ID) |
| Pay_Date  | 支付日期 | date         | 是              | 否                     | 否               |
| Pay_Money | 支付金额 | float(8,2)   | 是              | 否                     | 否               |

- 账户表(account)

|   列名    | 中文含义 | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键      |
| :-------: | -------- | ------------ | --------------- | ---------------------- | ------------- |
| AccountID | 贷款号   | decimal(8,0) | 否              | 是                     | 否            |
|   Name    | 支付日期 | varchar(10)  | 是              | 否                     | 是(bank.Name) |
|   Money   | 支付金额 | float(8,2)   | 是              | 否                     | 否            |

- 信用卡(credit)

|    列名     | 中文含义 | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键              |
| :---------: | -------- | ------------ | --------------- | ---------------------- | --------------------- |
|  AccountID  | 账户号   | decimal(8,0) | 否              | 是                     | 是(account.AccountID) |
| Limit_Money | 透支额度 | float(8,2)   | 是              | 否                     | 否                    |

- 储蓄(saving)

|   列名    | 中文含义 | 类型(长度)   | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键              |
| :-------: | -------- | ------------ | --------------- | ---------------------- | --------------------- |
| AccountID | 账户号   | decimal(8,0) | 否              | 是                     | 是(account.AccountID) |
|   Rate    | 透支额度 | float        | 是              | 否                     | 否                    |

- 客户(client)

|    列名    | 中文含义 | 类型(长度)    | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键              |
| :--------: | -------- | ------------- | --------------- | ---------------------- | --------------------- |
|     ID     | 身份证号 | decimal(18,0) | 否              | 是                     | 是(account.AccountID) |
|  Loan_ID   | 贷款号   | decimal(8,0)  | 是              | 否                     | 是(loan.Loan_ID)      |
| ClientName | 姓名     | text          | 是              | 否                     | 否                    |
|    Tel     | 电话     | decimal(11,0) | 是              | 否                     | 否                    |
|  Address   | 家庭住址 | text          | 是              | 否                     | 否                    |

- 联系人(contactperson)

|       列名        | 中文含义 | 类型(长度)    | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键      |
| :---------------: | -------- | ------------- | --------------- | ---------------------- | ------------- |
|        ID         | 身份证号 | decimal(18,0) | 否              | 是                     | 是(client.ID) |
| ContactPersonName | 姓名     | decimal(8,0)  | 是              | 否                     | 否            |
|        Tel        | 电话     | text          | 是              | 否                     | 否            |
|       Email       | Email    | varchar(20)   | 是              | 否                     | 否            |
|    ContactType    | 联系     | text          | 是              | 否                     | 否            |

- 拥有表(拥有)

|    列名     | 中文含义     | 类型(长度)    | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键              |
| :---------: | ------------ | ------------- | --------------- | ---------------------- | --------------------- |
|  AccountID  | 账户号       | decimal(8,0)  | 否              | 是                     | 是(account.AccountID) |
|     ID      | 身份证号     | decimal(18,0) | 否              | 是                     | 是(client.ID)         |
| Recent_Date | 最近访问日期 | date          | 是              | 否                     | 否                    |

- 负责表(负责)

|      列名      | 中文含义     | 类型(长度)    | 允许为空 (Null) | 是否主键 (Primary Key) | 是否外键             |
| :------------: | ------------ | ------------- | --------------- | ---------------------- | -------------------- |
|   Job_number   | 账户号       | decimal(8,0)  | 否              | 是                     | 是(staff.Job_number) |
|       ID       | 身份证号     | decimal(18,0) | 否              | 是                     | 是(client.ID)        |
| principal_Type | 最近访问日期 | tinyint(1)    | 是              | 否                     | 否                   |



### 4 总结与体会 

先选出有较为明显属性的实体，然后根据描述逐步规划其他实体即可。















