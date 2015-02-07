\documentclass[11pt]{article}

\usepackage[utf8]{inputenc}
\usepackage{array}
\usepackage{multirow}

\usepackage[francais]{babel}
\usepackage[T1]{fontenc}
\usepackage{lmodern}
\usepackage{marvosym}
\usepackage{ifpdf}
\usepackage{eurosym}
\usepackage{float}

\ifpdf
\usepackage[pdftex]{graphicx}
\else
\usepackage[dvips]{graphicx}\fi

\pagestyle{empty}

\usepackage[top=1.7cm, bottom=1.4cm, left=1.7cm, right=1.4cm]{geometry}
\setlength{\parindent}{0pt}
\addtolength{\parskip}{6pt}

\begin{document}
\begin{minipage}[t]{.6\textwidth}
\raggedright
{
{
    {{ userFirstName}} {{ userLastName}} }
}\\[.35ex]
\textit{ {{ userTitle }} }\\~\\
\small
7 impasse André \bsc{Lartigue}\\
Bat F2 -- Appt 41\\
31500, Toulouse\\[.35ex]
\Telefon~06~84~33~52~93\\
\Letter~\texttt{antoine.roquemaurel@gmail.com}
\end{minipage}\\[1em]
%
\hfill
\begin{minipage}[t]{.99\textwidth}
\raggedleft
{~\\Association Française McKenzie (AFMcK)\\[.35ex]
\small
2 rue Charles \bsc{Piot}\\
38320, Eybens\\[.35ex]
\Telefon~04~76~40~79~39\\
\Letter~\texttt{jacky.otero@wanadoo.fr}
}
\end{minipage}
%
%
\begin{minipage}[t]{.1\textwidth}
\end{minipage}\\[2em]
%
\vspace{-12px}
\Large \textbf{Devis \no{}7 du \today}\\~\\
\normalsize
\textbf{AfMck -- Suite du logiciel de bilans et du site web afmck.fr}\\~\\
Ce devis est calculé sur la base de 105\euro{} par jour de
travail.


        \begin{table}[H]
                \centering
                \begin{tabular}{|p{3.2cm}|l|p{2cm}|r|}
        \hline
        \textbf{Application} &\textbf{Prestation} & \textbf{Nombre de jours} & \textbf{Tarif\footnotemark}\\
        \hline
                & Version multi-praticien & 9.5 & 997.5~\euro\\
        \cline{2-4}
        Logiciel \texttt{BilanMDT} & Affichage de statistiques
        simples & 2.5 & 262.5~\euro\\
        \cline{2-4}
                & Fenêtre de calcul de l'invalidité fonctionnelle & 1 & 105~\euro\\
        \cline{2-4}
        & Vidéo tutoriel sur le fonctionnement du logiciel & 1.5
        & 157.5~\euro \\
        \hline
        \textbf{Sous-Total}& &\textbf{14.5} & \textbf{1522.5~\euro}\\
        \hline
        Site web \texttt{afmck.fr}& Système de news & 1.5 & 157.5~\euro\\
        \cline{2-4}
        & Possibilité d'éditer l'intégralité des articles & 4 & 420~\euro\\
        \cline{2-4}
        & Nouvelle carte des praticiens automatisée & 2 &210~\euro\\
        \cline{2-4}
        & Formulaire d'inscription à divers événements & 2 & 210~\euro \\
        \cline{2-4}
        & Pages spécifiques pour des membres du CA & 2 & 210~\euro \\
        \cline{2-4}
        & Vidéo tutoriel sur le fonctionnement du site & 1.5 &
        157.5~\euro \\
        \hline
        \textbf{Sous-Total}& &\textbf{13} & \textbf{1365.0~\euro}\\
        \hline
        \hline
        \textbf{Total}& &\textbf{27.5} & \textbf{2887.5~\euro}\\
        \hline
\end{tabular}
\caption{Les différentes prestations à la tâche, leur nombre de jour de travail et le tarif associé}
\end{table}
Offre valable 3 mois à compter du \today.

\vfill
\raggedleft
\small
\begin{tabular}{c p{1.5cm} c}
\begin{minipage}[t]{.6\textwidth}
Le prestataire,\\
Le . . . . . . . . . . . . . .\\
Signature\\
~\\~
\end{minipage} & &
\begin{minipage}[t]{.6\textwidth}
Le client,\\
Bon pour accord,\\
Le . . . . . . . . . . . . . .\\
Signature\\
~\\~
\end{minipage}
\end{tabular}
\footnotetext[1]{TVA non applicable, article 293B du Code Général des Impôts}
\end{document}
