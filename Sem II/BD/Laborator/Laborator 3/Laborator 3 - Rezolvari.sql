-- Laborator 3 --

-- Exemplu Nonequijoin:
select last_name, salary, grade_level, lowest_sal, highest_sal
from employees, job_grades
where salary between lowest_sal and highest_sal;

select * from job_grades;

-- Join --

-- Natural Join --

select last_name, job_id, job_title
from employees
natural join jobs;

select *
from employees
natural join departments; -- Ia dupa coloana manager_id

select last_name department_name, location_id
from employees e, departments d
where e.department_id = d.department_id; -- 106 rezultate -> Grant nu are departament

-- SQL3 - USING --

select last_name department_name, location_id
from employees join departments using (department_id);

-- SQL3 - ON --
select last_name department_name, location_id
from employees e join departments d on (e.department_id = d.department_id);

-- dorim sa afisam si angajatii FARA departament -> (+)

select last_name, department_name, location_id
from employees e, departments d
where e.department_id = d.department_id (+);

-- dorim sa afisam TOTI angajatii chiar daca nu au departament

select last_name, department_name, location_id
from employees e left join departments d on (e.department_id = d.department_id);

-- dorim sa afisam TOATE departamentele chiar daca au sau nu angajati

select last_name, department_name, location_id
from employees e right join departments d on (e.department_id = d.department_id);

-- cele doua de mai sus plus afisarea intersectiei

select last_name department_name, location_id
from employees e full join departments d on (e.department_id = d.department_id);

-- Exercitii - JOIN --

-- 1 --

select ang.last_name, to_char(ang.hire_date, 'month-yyyy'), gates.last_name
from employees ang join employees gates on (ang.department_id = gates.department_id)
where initcap(gates.last_name) = 'Gates' and lower(ang.last_name) like '%a%' and initcap(ang.last_name) != 'Gates';

-- 2 --

select e.employee_id "Cod ang", e.last_name "Nume ang", d.department_id "Cod dep", department_name "Nume dep"
from employees e join employees t on (e.department_id = t.department_id)
                 join departments d on (e.department_id = d.department_id)
where lower(t.last_name) like '%t%'
order by 2; -- e.last_name - la fel

-- 3 -- 

select e.last_name, e.salary, job_title, city, country_name, k.last_name
from employees e join employees k on (e.manager_id = k.employee_id)
                 join jobs j on (e.job_id = j.job_id)
                 join departments d on (e.department_id = d.department_id)
                 join locations l on (d.location_id = l.location_id)
                 join countries c on (l.country_id = c.country_id)
where initcap(k.last_name) like 'King';

-- 4 --

select d.department_id, department_name, job_id, last_name, to_char(salary, '$99,999.00')
from employees e join departments d on (e.department_id = d.department_id)
where lower(department_name) like '%ti%'
order by department_name, last_name;

-- 5 --

-- varianta join

select last_name, department_name, location_id
from employees e full join departments d on (e.department_id = d.department_id); -- 106 + 1 + 16 = 123

-- varianta cu operatori pe multimi

-- dorim sa afisam TOTI angajatii chiar daca nu au departament

select last_name, department_name, location_id -- adaugand distinct la last_name, o sa ajung la 106
from employees e left join departments d on (e.department_id = d.department_id)

UNION -- elementele comunie si necomune luate o singura data

-- dorim sa afisam TOATE departamentele chiar daca au sau nu angajati

select last_name, department_name, location_id
from employees e right join departments d on (e.department_id = d.department_id);

-- 6 --

-- operatori pe multimi --

select department_id
from departments
where lower(department_name) like '%re%' -- 40, 70, 120, 140, 150, 250, 260

union

select department_id
from employees
where upper(job_id) like '%SA_REP%'; -- 80, NULL

-- join --

select distinct d.department_id
from employees e full join departments d on (e.department_id = d.department_id)
where lower(department_name) like '%re%' or upper(job_id) like '%SA_REP%'
order by 1;

-- 8 --

-- varianta 1 cu join
-- se afiseaza intersectia - elementele comune + toate departamentele chiar daca au sau nu angajati
select *
from employees e right join departments d on (e.department_id = d.department_id);

select d.department_id -- pentru ca in d - department_id este cheie primara si nu poate fi nnull
from employees e right join departments d on (e.department_id = d.department_id)
where employee_id is null;

-- sau
-- where e.department_id is null

-- varianta 2 (!!!!)

select department_id "Cod departament"
from departments -- din lista tuturor departamentelor (department_id este cheie primara)

minus -- scade

select department_id
from employees;  -- departamentele in care lucreaza angajati (department_id este cheie externa)

-- => obtinem departamentele fara angajati

-- 10 --

select last_name, hire_date
from employees
where hire_date > ( select hire_date
                    from employees
                    where initcap(last_name)='Gates'
                  ); -- subcerere prin care preluam data angajarii lui Gates

-- 11 --

-- subcerere nesincronizata care determina id-ul de departament pentru angajatul cu numele Gates

select department_id
from employees
where initcap(last_name) = 'Gates';

-- cererea principala --

select last_name, salary
from employees
where department_id = ( select department_id
                        from employees
                        where initcap(last_name) = 'Gates'
                      )
      and initcap(last_name) != 'Gates';
      
-- Se va inlocui Gates cu King?

select last_name, salary
from employees
where department_id IN ( select department_id
                         from employees
                         where initcap(last_name) = 'King'
                        )
      and initcap(last_name) != 'King';
      
-- Se poate inlocui operatorul = cu IN (nu si invers)

-- 12 --

-- subcerere prin care selectam angajatul care este manager

select employee_id
from employees
where manager_id is null;

-- cererea principala

select last_name, salary
from employees
where manager_id = (select employee_id
                    from employees
                    where manager_id is null);

-- metoda cu self join :  
-- from employees e join emmployees sef on (e.manager_id = sef.employee_id);

-- 13 --

SELECT last_name, department_id, salary
FROM employees
WHERE (department_id, salary) IN (  SELECT department_id, salary
                                    FROM employees
                                    WHERE commission_pct is not null
                                 );
                                 
-- 14 --

SELECT employee_id, last_name, salary
FROM employees
WHERE salary > (SELECT AVG(salary)
                FROM employees);
                
-- 15 --

select job_id 
from employees;

upper(job_id) like 'CLERK'

-- subcerere prin care selectam venitul pe care il au functionarii - %clerk%

select max(salary + salary * nvl(commission_pct, 0))
from employees
where upper(job_id) like '%CLERK%';


-- cererea principala

select *
from employees 
where salary + salary * nvl(commission_pct, 0) > (select max(salary + salary * nvl(commission_pct, 0))
                                                  from employees
                                                  where upper(job_id) like '%CLERK%')
order by salary desc;


-- varianta 2 --

select *
from employees 
where salary + salary * nvl(commission_pct, 0) > ALL (select salary + salary * nvl(commission_pct, 0)
                                                     from employees
                                                     where upper(job_id) like '%CLERK%')
order by salary desc;

>ANY -> inseamna ca este suficient sa fie mai mare decat salariul unui singur angajat (<=> mai mare decat minimul)

>ALL -> inseamna mai mare decat salariul oricarui functionar (mai mare decat maximul)

-- 16 --

SELECT last_name, department_name, salary
FROM employees e JOIN departments d USING (department_id)
WHERE commission_pct is null and
      e.manager_id IN (SELECT employee_id
                       FROM employees
                       WHERE commission_pct is not null
                       );
                       
-- 17 --

SELECT last_name, department_id, salary, job_id, employee_id
FROM employees
WHERE (nvl(commission_pct, -1), salary) IN
                (SELECT nvl(commission_pct, -1), salary
                 FROM employees e JOIN departments d USING (department_id)
                 JOIN locations l USING (location_id)
                 WHERE initcap(l.city) = 'Oxford'
                );
  
-- 18 --

select last_name, department_id, job_id
from employees join departments using (department_id) join locations using (location_id)
where initcap(city) like 'Toronto';