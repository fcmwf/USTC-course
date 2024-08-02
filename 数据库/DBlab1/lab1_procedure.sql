/*
我们假设 Book 表有一些书具有超级 ID，它们以字符串“00”开头。这些超级 ID 不
允许修改，同时也不允许其它书的 ID 修改为超级 ID。请设计一个存储过程，实现对
Book 表的 ID 的修改，但是以字符串“00”开头的超级 ID 不允许修改，同时也不允
许任何 ID 修改成“00”开头的超级 ID（本题要求不得使用外键定义时的 on update
cascade 选项，因为该选项不是所有 DBMS 都支持）。
*/
DELIMITER // 
CREATE PROCEDURE ID_Change(IN id VARCHAR(50), OUT status INT)
BEGIN

END//
DELIMITER;

