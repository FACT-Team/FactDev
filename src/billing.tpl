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
\usepackage{fancyhdr}

\ifpdf
\usepackage[pdftex]{graphicx}
\else
\usepackage[dvips]{graphicx}\fi

\pagestyle{empty}

\usepackage[top=1.7cm, bottom=1.4cm, left=1.7cm, right=1.4cm]{geometry}
\setlength{\parindent}{0pt}
\addtolength{\parskip}{6pt}
\fancypagestyle{firststyle}
{
\fancyhf{}
\rfoot{Page \thepage{} sur \pageref{LastPage}}
\lfoot{Devis{{type}} \no{}{{no}} du {{date}}}
\renewcommand{\headrulewidth}{0.0pt}
}

\fancypagestyle{apendixstyle}
{
\pagestyle{fancy}
\rfoot{Page \thepage{} sur \pageref{LastPage}}
\lfoot{Devis \no{}8 du \today}
\cfoot{}
}

\lhead{\leftmark}
\rhead{%
{{ title }}%
}

\begin{document}
    \thispagestyle{firststyle}
    \begin{minipage}[t]{.6\textwidth}
    {{#user}}
    \raggedright
    {
    {
    {{ firstName}} {{ lastName }}
    }
    }\\[.35ex]
    %
    \textit{%
    {{ title }}%
    }\\~\\
    %
    \small
    {{ address }}\\
    {{ postalCode}}, \bsc{ {{ city }} }\\[.35ex]
    \Telefon~{{ phone }}\\
    \Letter\texttt{%
    {{ email }}
    }
    {{/user}}
    \end{minipage}\\[1em]
    %
    \hfill
    \begin{minipage}[t]{.99\textwidth}
    \raggedleft
    {%
    {{#customer}}
    ~\\{{company}}\\[.35ex]
    \small
    {{address}}\\
    {{postalcode}}, \bsc{ {{city}} }\\[.35ex]
    \Telefon~{{ phone }}\\
    \Letter\texttt{ {{ email }} }
    {{/customer}}
    }
    \end{minipage}
    %
    %
    \begin{minipage}[t]{.1\textwidth}
    \end{minipage}\\[2em]
    %
    \vspace{-12px}
    {{#billing}}
    \Large \textbf{ {{type}} \no{}{{no}} du {{date}} }\\~\\
    \normalsize
    \textbf{ {{title}} }\\
    {{description}}\\~\\
    {{/billing}}
    \begin{table}[H]
        \centering
        \begin{tabular}{|p{4.2cm}|p{8cm}|p{2cm}|r|}
            \hline
            \textbf{Application} &\textbf{Prestation} & \textbf{Nombre de jours} & \textbf{Tarif\footnotemark}\\
            \hline
            {{#table}}
                {{#contributories}}
                    \texttt{[{{indexproject}}]} {{ nameproject }} &  \texttt{[{{indexproject}}.{{indexcontributory}}]} {{ contributoryDescription }} & {{ nbHours }} & {{ price }}\euro{}\\
                    \hline
                {{/contributories}}
            {{/table}}
            \hline
            \textbf{Total}& &\textbf{ {{ totalQuantity }} } & \textbf{ {{totalRate }} ~\euro}\\
            \hline
        \end{tabular}
        \caption{Les différentes prestations à la tâche, leur nombre de jour de travail et le tarif associé}
    \end{table}

    \vfill
    \raggedleft
    \small
    % For Billing… TODO
    %	\begin{tabular}{c p{1.5cm} c}
    %\begin{minipage}[t]{.6\textwidth}
    %	Le prestataire,\\
    %Le . . . . . . . . . . . . . .\\
    %	Signature\\
    %~\\~
    %	\end{minipage} & &
    %\begin{minipage}[t]{.6\textwidth}
    %	Le client,\\
    %Bon pour accord,\\
    %	Le . . . . . . . . . . . . . .\\
    %Signature\\
    %	~\\~
    %	%\end{minipage}
    %	\end{tabular}
    \footnotetext[1]{TVA non applicable, article 293B du Code Général des Impôts}

    \pagestyle{apendixstyle}
    \newpage
    \appendix
    \section{Détails des projets}
        \begin{description}
        {{#table}}
            {{#contributories}}
            \item[\texttt{[{{indexproject}}]} {{ nameproject }}] {{ descriptionproject }}
            {{/contributories}}
        {{/table}}
        \end{description}

    \section{Détails des prestations}
        \begin{description}
        {{#table}}
            {{#contributories}}
            \item[\texttt{[{{indexproject}}.{{indexcontributory}}]}] {{ contributoryLongDescription}}
            {{/contributories}}
        {{/table}}

        \end{description}
\end{document}
