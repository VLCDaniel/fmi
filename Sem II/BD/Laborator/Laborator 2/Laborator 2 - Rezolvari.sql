-- LABORATOR 2 --


select to_number ('-25.6989', 9999.999999)
from dual;

select rpad(lower('info0'), 7, 'x') -- la 3, taie caracterul 0
from dual;

-- 2 varianta 1 --

select initcap(first_name) Prenume, upper(last_name) Nume, length(last_name) Lungime -- Putem rula prin selectie
from employees
where upper(last_name) like 'J%' or upper(last_name) like 'M%' or upper(last_name) like '__A%'
order by length(last_name) desc;

-- 2 varianta 2 --

select initcap(first_name) Prenume, upper(last_name) Nume, length(last_name) Lungime
from employees
where upper(last_name) like 'J%' or upper(last_name) like 'M%' or substr(upper(last_name), 3, 1) = 'A'
order by length(last_name) desc;

-- 4 --

select employee_id, last_name, length(last_name) Lungime, instr(upper(last_name), 'A', 1, 1) PozitieLitera
from employees
where substr(lower(last_name), -1) = 'e';

select round(to_date('31-12-2020', 'dd-mm-yyyy') - sysdate, 100)
from dual;

-- tema ex 5 --

select *
from employees
where MOD(round(sysdate - hire_date), 7) = 0;

-- 6 --

select employee_id, last_name, salary, round(salary * 1.15, 2) "Salariu nou",
        round(salary * 1.15/100, 2) "Numar sute"
from employees
where mod(salary, 1000) != 0; -- Pentru diferit exista si <>, ^=

-- 7 --

select last_name "Nume angajat", rpad(to_char(hire_date), 20, 'X') "Data angajarii" -- nu e nevoie de to_char, face conversia automat
from employees
where commission_pct is not null;

-- 8 --

select to_char(sysdate+30, 'MONTH DD YYYY HH24:MI:SS') Data
from dual;

-- 10 a) --

select to_char(sysdate+12/24, 'DD/MM HH24:MI:SS') Data
from dual;

-- 10 b) --

select to_char(sysdate + 5/60/24, 'DD/MM HH24:MI:SS') Data
from dual;

-- 13 IMPORTANT --

select last_name, NVL(to_char(commission_pct), 'Fara comision') "Comision"
from employees;

-- 14 --

select last_name, salary, commission_pct
from employees
where nvl(salary + salary * commission_pct, salary) > 10000;

-- sau --

select last_name, salary, commission_pct
from employees
where salary + salary * nvl(commission_pct, 0) > 10000;

select 10 + 10* null
from dual; -- null

select 10 + null
from dual; -- null

-- 15 --

SELECT last_name, job_id, salary,
             DECODE(job_id,
             'IT_PROG', salary*1.1,
             'ST_CLERK', salary*1.15,
             'SA_REP', salary*1.2,
             salary) "Salariu renegociat"
FROM employees;

-- sau

SELECT last_name, job_id, salary,
 CASE job_id WHEN 'IT_PROG' THEN salary* 1.1
             WHEN 'ST_CLERK' THEN salary* 1.15
             WHEN 'SA_REP' THEN salary* 1.2
 ELSE salary
 END " Salariu renegociat"
 FROM employees;
 
 -- JOIN --
 
 select * from departments;
 
 select * from employees;
 
-- 16 --

select employee_id, department_name
from employees e, departments d; -- produs cartezian

select employee_id, department_name
from employees e, departments d
where e.department_id = d.department_id; -- 106 angajati din totalul de 107

-- De ce afiseaza 106 in loc de 107?

select employee_id, last_name
from employees
where department_id is null; -- 1 angajat are department_id Null: 178 Grant

-- In tabelul employees department_id este cheie externa deci poate fi null
-- De aceea exista un angajat fara departament

-- Vrem sa afisam si angajatii care nu au departament
-- Exista simbolul (+) care se pune in dreptul coloanei(din conditia de JOIN) unde este deficit de informatie

select employee_id, department_name
from employees e, departments d
where e.department_id = d.department_id (+);

-- Vrem sa afisam si departamentele care nu au angajati

select employee_id, department_name
from employees e, departments d
where e.department_id(+) = d.department_id;

-- ALIAS-UL

select employee_id, department_name, d.department_id
from employees, departments d
where employees.department_id = d.department_id;

-- Utilizam ON:

select employee_id, department_name
from employees e JOIN departments d USING (department_id);

-- 17 --

select job_title, e.job_id
from jobs j, employees e
where department_id = 30 and e.job_id = j.job_id;

-- 18 --

select last_name, department_name, location_id
from employees e, departments d
where e.department_id = d.department_id AND commission_pct is not null;

-- 19 --

select last_name, job_title, department_name
from employees e, jobs j, departments d, locations l
where e.job_id = j.job_id and e.department_id = d.department_id and d.location_id = l.location_id and initcap(l.city) = 'Oxford';

-- 20 --

select ang.employee_id Ang#, ang.last_name Angajat, sef.employee_id Mgr#, sef.last_name Manager
from employees ang, employees sef
where ang.manager_id = sef.employee_id(+);

-- 22 --

select ang.last_name, ang.department_id, coleg.last_name
from employees ang, employees coleg
where ang.department_id = coleg.department_id and ang.employee_id > coleg.employee_id;

-- 24 --

select ang.last_name, ang.hire_date, gates.hire_date, gates.last_name
from employees ang, employees gates
where ang.hire_date > gates.hire_date and gates.last_name = 'Gates';

-- Tema 23, 25 --

-- 23 --

select last_name, e.job_id, job_title, department_name, salary
from employees e, jobs j, departments d
where e.job_id = j.job_id and e.department_id = d.department_id;

-- 25 --

select ang.last_name Angajat, ang.hire_date Data_ang, sef.last_name Manager, sef.hire_date Data_mgr
from employees ang, employees sef
where ang.hire_date < sef.hire_date and ang.manager_id = sef.employee_id;