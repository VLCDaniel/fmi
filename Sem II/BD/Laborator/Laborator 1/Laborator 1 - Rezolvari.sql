-- LABORATOR 1 --

select * from employees; -- Sintaxa pentru a afisa toate datele dintr-un tabel

select * from departments;

select * from jobs;

desc employees; -- Sintaxa pentru a descrie atributele unui tabel


-- cheia primara -> este o coloana sau o combinatie de coloane
--               -> este UNICA - nu se repeta
--               -> nu poate fi null
              
-- cheia externa -> este o coloana
--               -> poate fi null
--               -> daca se afla intr-un tabel -> atunci se afla si in tabelul pe care il refera
--               -> cheia externa se poate repeta



-- Exercitii --

-- 1) - 5)
--    Chei Primare: (PK)
--    Chei Externe: (FK)
              
select job_id from employees; -- 107 joburi deoarece job_id este cheie externa si se poate repeta => avem 107 angajati deci avem 107 joburi

select job_id from jobs; -- 19 joburi unice deoarece job_id este cheie primara si nu se poate repeta

select distinct job_id from employees; -- la fel ca unique, alegem care e mai usor de retinut

select unique job_id from employees;

SELECT employee_id, last_name, salary * 12 "ANNUAL SALARY" -- intre ghilimele -alias, putem folosi alias fara ghilimele dar fara spatiu; fara ghilimele, transforma textul in upper.
FROM employees;

SELECT employee_id ID, last_name, salary * 12 as ANNUALSALARY
FROM employees;

-- operatorul de concatenare -> ||

select last_name || job_id "asd"
from employees;

select last_name, salary
from employees
where salary > 2850;

select last_name, salary
from employees
where salary not between 1500 and 2850;

select last_name, salary
from employees
where salary >= 1500 and salary <= 2850;

-- 6 --

select first_name|| last_name|| email|| phone_number|| hire_date|| job_id|| salary|| commission_pct|| manager_id|| department_id "Informatii complete"
from employees;

-- 8 --

select last_name, department_id
from employees
where employee_id = 104;

-- 9.1 --

select first_name, last_name, salary
from employees
where salary between 3000 and 7000;

-- 9.2 --

select first_name, last_name, salary
from employees
where salary >= 3000 and salary <= 7000;

-- 10 --

select first_name, job_id, hire_date
from employees
where hire_date between '20-FEB-1987' and '1-MAY-1989'
order by hire_date;

-- 11 - varianta 1 --

select first_name, department_id
from employees
where department_id IN (10,30)
order by first_name;

-- 11 - varianta 2 --

select first_name, department_id
from employees
where department_id IN (10,30)
order by 1;

-- 11 - varianta 3 --

select first_name Nume, department_id
from employees
where department_id IN (10,30)
order by Nume;

-- 12 --

select first_name "Angajat", salary "Salariu lunar" -- merge fara ghilimele daca nu are spatii
from employees
where salary > 1500 and department_id IN (10,30)
order by first_name;

-- 13 --

select sysdate
from dual;

select sysdate
from employees;

desc dual;
select * from dual;

select 2+4
from dual;

--to_char(data, format);
--to_number
--to_date

select to_char(sysdate, 'day-mon-year hh12 mi ss sssss d dd ddd')
from dual;

-- 14 --

select last_name, hire_date
from employees
where hire_date like('%87');  -- merge si fara paranteze


-- %X% -> abcXaaabbbccc
-- x% -> incepe cu x
-- %x -> se termina cu x


-- sau:

select lastname, hire_date
from employees
where to_char(hire_date, 'YYYY')='1987';

desc hire_date;

-- 15 --

select manager_id
from employees;

select last_name, job_id, manager_id
from employees
where manager_id is null;

-- 16 --

select commission_pct
from employees;

select first_name, salary, commission_pct
from employees
where commission_pct is not null
order by salary desc, commission_pct desc; -- prima ordonare are prioritate

-- 17 valorile null sunt plasate la inceput --

select last_name, salary, commission_pct
from employees
order by salary desc, commission_pct desc;

-- 18 --

select last_name
from employees;

select last_name
from employees
where lower(last_name) like '__a%'; -- initcap(last_name) -> prima litera mare, restul mici

-- 19 --

select last_name
from employees
where lower(last_name) like '%l%l%' and (department_id = 30 or manager_id = 102);

-- 20 --

select job_id
from employees;

select first_name, job_id, salary
from employees
where (job_id like '%CLERK%' or job_id like '%REP%') and salary not in (1000, 2000, 3000);