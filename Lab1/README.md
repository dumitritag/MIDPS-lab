La perechea de laborator am creat un cont pe github si un repozitoriu, acasa efectuind task-urile am intilnit probleme, comanda git push nu se executa. Am incercat sa inlatur problema, dar nu am reusit, de aceea am creat un nou cont. Acum in repozitoriu nou sunt 2 contribuitori, sper ca asta nu e o problema.

Task-urile efectuate sunt:

1.Initializarea unui repositoriu si configurarea VCS
 Initial a fost creat un cont pe GitHub care contine repozitoriul laboratorului efectuat. Am creat repozitoriul meu \textit {MIDPS$-$lab}. A fost stabilita conexiunea cu serverul prin generarea keygen-ului SSH prin instructiunea \textit {ssh-keygen}, ea fiind adaugata in setari.  Dupa ce am clonat repozitoriul, folosind comanda \textit {git clone shhlik} , am configurat contul cu comenzile \textit {git config $-$global user.name "YourName"} si \textit {git config $-$global user.email "youremail@domain.com"}  Am creat fisierele .gitignore si README in repozitoriu si cu ajutorul comenzii \textit {git pull} le-am adaugat in masina locala. In masina locala am creat 5 mape, fiecare continind cite un fiser README si le-am adaugat in repozitoriu cu comenzile \textit {git add .} , \textit {git commit} si \textit {git push} . Commiturile sunt schimbarile salvate in poiectu nostru. Fiecare commit are un mesaj asociat, in care descrim ce schimbare am facut. In mapa Lab1 din masina locala am creat un fisier myfile.txt cu continutul "Welcome!" si l-am adaugat in repozitoriu.

2. Crearea branch-urilor 
Branch-ul implicit in Git este master, comanda \textit {git init} il creeaza implicit. Am creat 2 branch-uri noi: branch1 si branch2 cu ajutorul comenzii \textit {git branch <branchname>}. Aceasta creeaza un nou pointer la ultimul commit. Pentru a comuta la un branch nou am folosit comanda \textit {git checkout <branchname>}. Am modificat fisierul myfile.tx, l-am adaugat la branch-urile si am facut primele commituri in noile branch-uri.

3. Track remote origin
 Am creat un nou branch newbranch  to track remote origin, folosind comanda \textit {git branch --track <branchname> origin/master}. Am creat un nou fisier new.txt, l-am adaugat, am facut commit si cu comanda \textit {git push origin <branchname>} am adaugat commitul in newbranch iar cu comanda \textit {git push origin HEAD:master} in master branch.
 
4. Resetarea unui branch la commitul anterior
 Pentru rescrierea commitului anterior am folosit comanda \textit {git commit --amend}. Pentru resetarea unui branch la commitul anterior am folosit comanda \textit {git revert HEAD}.
 
5. Salvarea temporara a schimbarilor
 Uneori facem schimbari care nu dorim sa le facem commit dar dorim sa le salvam, asta putem face cu comanda \textit {git stash}.
 
6. Folosirea fisierului .gitignore
 Pentru a vedea cum influenteaza fisierul .gitignore, am adaugat in fisierul .gitignore *.txt si am creat un nou fisier de tip txt, am aplicat comanda git add si acest fisier a fost ignorat.
 
7. Merge 2 branches
 Merge 2 branches inseamna a le integra intr-un singur branch. Pentru aceasta am folosit comanda \textit {git merge <branchname>}.
 
8. Rezolvarea conflictelor a 2 branch-uri 
 Daca avem 2 branches, in ambele a fost schimbat aceeasi parte a unui fisier si dorim sa facem merge la ambele va aparea un conflict. Acest conflict putem sa-l rezolvam manual, modificind fisierul care a cauzat conflictul. O alta metoda este prin folosirea comenzii \textit {git rebase master}. 
 
9. Folosirea tag-urilor
 Un tag este folosit pentru a eticheta si a marca un commit. Sunt 2 tipuri de tag-uri lightweight, folosim comanda \textit {git tag <tagname>} si annotated, comanda folosita este \textit {git tag -am "message" <tagname>}.
