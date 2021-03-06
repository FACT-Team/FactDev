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
\usepackage{lastpage}
\usepackage[hidelinks]{hyperref}
\usepackage{ifthen}

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
{{#billing}}

\rfoot{Page \thepage{} sur \pageref{LastPage}}
\lfoot{ {{type}} \no{}{{no}} du {{date}} }
\renewcommand{\headrulewidth}{0.0pt}
}

\fancypagestyle{apendixstyle}
{
\pagestyle{fancy}
\rfoot{Page \thepage{} sur \pageref{LastPage}}
\lfoot{ {{type}} \no{}{{no}} du {{date}} }
\cfoot{}
}
{{/billing}}

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

    \newcommand{\complementUser}{%
    {{complement}}%
    }
    \ifthenelse{\equal{\complementUser}{}}{
    }
    {
        \complementUser{}\\
    }
   {{ postalCode}}, \bsc{ {{ city }} }\\[.35ex]
	{{#phone}}
        \Telefon~{{ phone }}\\[.35ex]
	{{/phone}}
	{{#mobilePhone}}
        \Mobilefone~{{ mobilePhone }}\\[.35ex]
	{{/mobilePhone}}
    \Letter\texttt{~{{ email }} }
    \newcommand{\websiteUser}{%
    {{website}}%
    }
    \ifthenelse{\equal{\websiteUser}{}}{
    }
    {
        \\\Mundus~\texttt{%
            \websiteUser{}
        }
    }\newline~\newline
    Numéro SIRET: {{siretNumber}}
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
%
\newcommand{\complementCustomer}{%
{{\complement}}%
}
\ifthenelse{\equal{\complementCustomer}{}}{
}
{
    \complementCustomer{}\\
}
%
    {{postalcode}}, \bsc{ {{city}} }\\[.35ex]
    {{#phone}}
    \Telefon~{{ phone }}\\[.35ex]
    {{/phone}}
    {{#mobilePhone}}
    Mobilefone~{{ mobilePhone }}\\[.35ex]
    {{/mobilePhone}}
    {{#fax}}
    \Faxmachine~{{ fax }}\\[.35ex]
    {{/fax}}
    \Letter\texttt{~{{ email }} }
    \newcommand{\websiteCustomer}{%
    {{website}}%
    }
    \ifthenelse{\equal{\websiteCustomer}{}}{
    }
    {
        \\\Mundus~\texttt{\websiteCustomer}
    }

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
        \hspace{-30px}
        \begin{tabular}{|p{3.5cm}|p{1.75cm}|p{8.2cm}|p{1.2cm}|p{1.2cm}|r|}
            \hline
            \textbf{Application} & \textbf{Tarif journalier} &\textbf{Prestation} & \textbf{Qté.}& \textbf{Unité} & \textbf{Tarif\footnotemark}\\
            {{#table}}
                {{#contributories}}

                {{#firstcontributory}}
                \cline{0-5}
                    \multirow{ {{ nbcontributories }} }{*}{\texttt{[{{indexproject}}]} {{ nameproject }} } &
                    \multirow{ {{ nbcontributories }} }{*}{ \begin{minipage}{1.75cm}\begin{flushright} {{rateproject}}~\euro{} \end{flushright}\end{minipage} }
                {{/firstcontributory}}
                {{^firstcontributory}}
                &
                {{/firstcontributory}}
                    & \texttt{[{{indexproject}}.{{indexcontributory}}]} {{ contributoryDescription }} &
                     \begin{minipage}{1.2cm}\begin{flushright} {{ quantity }}\end{flushright}\end{minipage}&
                     \begin{minipage}{1.2cm}\begin{flushright} {{ unit }}\end{flushright}\end{minipage}&
                     {{ price }}~\euro{}\\
                \cline{3-6}

                {{#lastcontributory}}
                \cline{0-2}
                \multicolumn{3}{|r|}{\textbf{Sous-Total} } & \begin{minipage}{1.2cm}\begin{flushright} \textbf{ {{ subquantity }} } \end{flushright}\end{minipage}&
                \begin{minipage}{1.2cm}\begin{flushright} {{subunit}} \end{flushright}\end{minipage}& \textbf{ {{subtotal}}~\euro{}}\\
                {{/lastcontributory}}
                {{/contributories}}

            {{/table}}
            \hline
            \hline
            \multicolumn{3}{|r|}{\textbf{Total} } & \begin{minipage}{1.2cm}\begin{flushright} \textbf{ {{ totalQuantity }} }\end{flushright}\end{minipage} &
            \begin{minipage}{1.2cm}\begin{flushright} Jours\end{flushright}\end{minipage}&
            \textbf{ {{ totalRate}}~\euro{}}\\
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
            \item[\texttt{[{{indexproject}}]} {{ nameproject }}] {{ descriptionproject }}
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
