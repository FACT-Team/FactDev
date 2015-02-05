<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>md_tests_QTestRunner_README</name>
    <title>QTestRunner</title>
    <filename>dc/d04/md_tests_QTestRunner_README</filename>
  </compound>
  <compound kind="class">
    <name>AddContributoryDialog</name>
    <filename>d9/dfa/classAddContributoryDialog.html</filename>
    <member kind="function">
      <type></type>
      <name>AddContributoryDialog</name>
      <anchorfile>d9/dfa/classAddContributoryDialog.html</anchorfile>
      <anchor>a75ef0d55afcf2cc30a702bb4792ccc2b</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AddProjectDialog</name>
    <filename>d0/d23/classAddProjectDialog.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>checkFields</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>a781e8cf3e919f32706ddb15b13d2ab25</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AddProjectDialog</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>abb96542ad074344f634d0ff834e65f03</anchor>
      <arglist>(int id=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AddProjectDialog</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>a7acdb6d0e61449ad9376802d90162d2c</anchor>
      <arglist>(int noRowCustomer, int idProject=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>adb873176b67a671fc417e7ab21389c21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>a3e6011001312acd234f2352f1a796f0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>ad8c428e08b08a7aa36f7c6801810c0cd</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AddQuoteDialog</name>
    <filename>d6/dd0/classAddQuoteDialog.html</filename>
    <member kind="function">
      <type></type>
      <name>AddQuoteDialog</name>
      <anchorfile>d6/dd0/classAddQuoteDialog.html</anchorfile>
      <anchor>abffc6ab5550345bf6cfa57d0a4f2b8b4</anchor>
      <arglist>(int idCustomer=0, int id=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>d6/dd0/classAddQuoteDialog.html</anchorfile>
      <anchor>ae9ad47fdc3babc6546ed3708873c0d05</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>d6/dd0/classAddQuoteDialog.html</anchorfile>
      <anchor>a5926a2d7b00ddc3f623b34ee4489277f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>d6/dd0/classAddQuoteDialog.html</anchorfile>
      <anchor>a8d639a263877c3bb10bda6ece25f0234</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BillingDatabase</name>
    <filename>d0/dad/classBillingDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>Models::Billing *</type>
      <name>getBilling</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a5c1d5b79e690df9b63a053e60626cf36</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getBillingsTable</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>aec74e952e83d47332a5e07109588faa9</anchor>
      <arglist>(const int idProject)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addBilling</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a2b99c012790171e9ea025fc2b60cc42c</anchor>
      <arglist>(const Models::Billing &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateBilling</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a6d69e6294120f618c3d20b5dd1e1b8a1</anchor>
      <arglist>(const Models::Billing &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeBilling</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a82e2c5503dc9b47a42bd592efece5532</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addBillingProject</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>ac8a618d0c2420f8db417c65fcdbc85c6</anchor>
      <arglist>(const int idProject, const int idBilling, const int idContributory)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getMaxBillingNumber</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a342ccaed3192fadc91a15468a7d3d565</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getMaxQuoteNuber</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>adc3351f464ec63e15ba663ba4fb24f8f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>lastError</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a17465cc3fe0a8b853f96599e0584cc84</anchor>
      <arglist>(const QSqlQuery &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>testCases</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a702ce00658c10518d2ddbbd234a0c67d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cleanDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a6c7ca19f0107fdad000c268fc2b14ac0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>executeFile</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a06216acb010c0ea93ac2a53aa46256c2</anchor>
      <arglist>(QString pName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>openTransaction</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>ace56e75784477e79197485e9b5980804</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>closeTransaction</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a8322990bcba006d0d82ac069ad6e0307</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>close</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>ab89cb07242f0ab1d4058974bf3e7cf19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>open</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a0d0134e05c8f2dc4fcbbb2f36c02a779</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Database</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a84d399a2ad58d69daab9b05330e1316d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a8b03d7f4a92325b9e519fd3f8a2e245c</anchor>
      <arglist>(QSqlDatabase sql)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a2dc260583a49889bed8097e21953594e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static BillingDatabase *</type>
      <name>instance</name>
      <anchorfile>d0/dad/classBillingDatabase.html</anchorfile>
      <anchor>a80a2bc546d92863a8b54786cfd832189</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Database *</type>
      <name>instance</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>aa334760d1e18f82a344fb696547bfa5c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Database</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a4703c80e6969d33565ea340f768fdadf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>QVariant</type>
      <name>value</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a88f0ccd102fc421fb10ddad0fd94e8c1</anchor>
      <arglist>(const QSqlQuery &amp;q, const QString &amp;champ)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QSettings *</type>
      <name>_settings</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a6cde413cb6d644c835406c09ec37947e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QSqlDatabase</type>
      <name>mDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a64b9dbb3a5e6f42447a24caf726782e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>QList&lt; Database * &gt;</type>
      <name>_instances</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a9202583fae82c7f4ecbda6cb11b978c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static Database *</type>
      <name>_instance</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a4f435119a26cf1b0b8cca652a74c70b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static bool</type>
      <name>_dbInstance</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a923366369d404e62e9e77111d7c21bab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static bool</type>
      <name>isOpen</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a8ed9b8afac7134aa48e40c48780b240f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BillingDatabaseTest</name>
    <filename>d1/db1/classBillingDatabaseTest.html</filename>
  </compound>
  <compound kind="class">
    <name>BillingModelTest</name>
    <filename>dc/d0c/classBillingModelTest.html</filename>
  </compound>
  <compound kind="class">
    <name>CheckCity</name>
    <filename>de/de9/classCheckCity.html</filename>
    <base>CheckFieldsLetters</base>
    <member kind="function">
      <type></type>
      <name>CheckCity</name>
      <anchorfile>de/de9/classCheckCity.html</anchorfile>
      <anchor>a639556875bd01b8cee5cf92759972ca5</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CheckFieldsLetters</name>
      <anchorfile>de/d19/classCheckFieldsLetters.html</anchorfile>
      <anchor>a5a8af8c6e89dc19c7e98304e5f40081d</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>de/d19/classCheckFieldsLetters.html</anchorfile>
      <anchor>a62574deb407fe83456e46381425a7b46</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CheckUntilField</name>
      <anchorfile>dc/db9/classCheckUntilField.html</anchorfile>
      <anchor>a7b3789fe02959e488b35a0e79362f786</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>dc/db9/classCheckUntilField.html</anchorfile>
      <anchor>acfb9e2f95bebcb5b5d2337e3ac4f4d47</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>CheckQLineEdit</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>acc48f17bfddb47e4101a7aedbace7783</anchor>
      <arglist>(QWidget *parent=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>displayCheckValidFieldIcon</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>a730ae162e31a8c76f5532d3f3c8903c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>displayCheckNoValidFieldIcon</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>aaf3b88a48a806bc6215f685bc45937a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QPushButton *</type>
      <name>getBtnValid</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>a87ea56ee9e7833b77c408be489b116e3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBtnValid</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>a28bb08ffaac7da25289a7d93639ba00f</anchor>
      <arglist>(QPushButton *getBtnValid)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isValid</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>a50e64b1790af6edb2c587e098c8b99f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>fieldTextChanged</name>
      <anchorfile>d1/da9/classCheckQLineEdit.html</anchorfile>
      <anchor>a137569359307e1b17449af3a72c5e80e</anchor>
      <arglist>(const QString &amp;text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckCountry</name>
    <filename>d6/d52/classCheckCountry.html</filename>
    <base>CheckFieldsLetters</base>
    <member kind="function">
      <type></type>
      <name>CheckCountry</name>
      <anchorfile>d6/d52/classCheckCountry.html</anchorfile>
      <anchor>aa6aa76f22635d879105449836dd68bbd</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckEmail</name>
    <filename>da/d1d/classCheckEmail.html</filename>
    <base>CheckQLineEdit</base>
    <member kind="function">
      <type></type>
      <name>CheckEmail</name>
      <anchorfile>da/d1d/classCheckEmail.html</anchorfile>
      <anchor>a385bd05063deaf42fc02918b9348c8ac</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>da/d1d/classCheckEmail.html</anchorfile>
      <anchor>a544d7656d36bd463391fe2f4dd3e13c6</anchor>
      <arglist>(const QString text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckFieldsLetters</name>
    <filename>de/d19/classCheckFieldsLetters.html</filename>
    <base>CheckUntilField</base>
  </compound>
  <compound kind="class">
    <name>CheckName</name>
    <filename>dc/d14/classCheckName.html</filename>
    <base>CheckFieldsLetters</base>
    <member kind="function">
      <type></type>
      <name>CheckName</name>
      <anchorfile>dc/d14/classCheckName.html</anchorfile>
      <anchor>a4a7fe601d6fd5e8576498e2d953df614</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckPhone</name>
    <filename>d0/ddb/classCheckPhone.html</filename>
    <base>CheckUntilField</base>
    <member kind="function">
      <type></type>
      <name>CheckPhone</name>
      <anchorfile>d0/ddb/classCheckPhone.html</anchorfile>
      <anchor>a491bceb9add48e7668162fc8ec511550</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>d0/ddb/classCheckPhone.html</anchorfile>
      <anchor>ac60f1428fc89e1b2630db022e14509ed</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCountry</name>
      <anchorfile>d0/ddb/classCheckPhone.html</anchorfile>
      <anchor>a3dd528db0e731b23df0524e41415d05e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCountry</name>
      <anchorfile>d0/ddb/classCheckPhone.html</anchorfile>
      <anchor>a2a4a30d0a69611f72c539cc17919ccc9</anchor>
      <arglist>(const QString &amp;country)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckPostalCode</name>
    <filename>dc/d63/classCheckPostalCode.html</filename>
    <base>CheckUntilField</base>
    <member kind="function">
      <type></type>
      <name>CheckPostalCode</name>
      <anchorfile>dc/d63/classCheckPostalCode.html</anchorfile>
      <anchor>a98cce06b95b46bf285cf6bc6e52cbfcb</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>dc/d63/classCheckPostalCode.html</anchorfile>
      <anchor>ad91ba5622617675fbb5c767036163142</anchor>
      <arglist>(QString text)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCountry</name>
      <anchorfile>dc/d63/classCheckPostalCode.html</anchorfile>
      <anchor>a3691eb5a484579a77622529ae25261a4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCountry</name>
      <anchorfile>dc/d63/classCheckPostalCode.html</anchorfile>
      <anchor>ac82e538c932bd9165d3d40ea949baa4b</anchor>
      <arglist>(const QString &amp;country)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckQLineEdit</name>
    <filename>d1/da9/classCheckQLineEdit.html</filename>
    <base>ICheckField</base>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>check</name>
      <anchorfile>d5/d75/classICheckField.html</anchorfile>
      <anchor>a6bd42b4d49c165cdd92822135123fd4b</anchor>
      <arglist>(QString text)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckSiretNumber</name>
    <filename>d7/d29/classCheckSiretNumber.html</filename>
    <base>CheckQLineEdit</base>
    <member kind="function">
      <type></type>
      <name>CheckSiretNumber</name>
      <anchorfile>d7/d29/classCheckSiretNumber.html</anchorfile>
      <anchor>a0581c0a2d6c0c1a62dab77515422b194</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>d7/d29/classCheckSiretNumber.html</anchorfile>
      <anchor>aaf0a1411e380789062564bd992e72c1b</anchor>
      <arglist>(QString text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CheckUntilField</name>
    <filename>dc/db9/classCheckUntilField.html</filename>
    <base>CheckQLineEdit</base>
  </compound>
  <compound kind="class">
    <name>CheckValidField</name>
    <filename>dc/d93/classCheckValidField.html</filename>
    <base>CheckQLineEdit</base>
    <member kind="function">
      <type></type>
      <name>CheckValidField</name>
      <anchorfile>dc/d93/classCheckValidField.html</anchorfile>
      <anchor>acfb0bb44b22b5355a227273f439210b8</anchor>
      <arglist>(QWidget *w=0, QPushButton *btn=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>check</name>
      <anchorfile>dc/d93/classCheckValidField.html</anchorfile>
      <anchor>a192b1c9c84ea8897661425fd3c0b9e8e</anchor>
      <arglist>(QString text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ComboBoxModelWidget</name>
    <filename>d5/d79/classComboBoxModelWidget.html</filename>
  </compound>
  <compound kind="class">
    <name>ContributoriesDatabaseTest</name>
    <filename>d8/df7/classContributoriesDatabaseTest.html</filename>
  </compound>
  <compound kind="class">
    <name>ContributoriesTableModel</name>
    <filename>d4/d24/classContributoriesTableModel.html</filename>
    <member kind="function">
      <type></type>
      <name>ContributoriesTableModel</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a7fb98c9bddccafe26319fc75ee92c80b</anchor>
      <arglist>(QObject *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>rowCount</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>abab4002f904986345347dd43aa815380</anchor>
      <arglist>(const QModelIndex &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>columnCount</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>ae4734e8d3be16e8be792fe6eacee8095</anchor>
      <arglist>(const QModelIndex &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>QVariant</type>
      <name>data</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a6be653469563e4a78ce5934963f9c602</anchor>
      <arglist>(const QModelIndex &amp;index, int role) const </arglist>
    </member>
    <member kind="function">
      <type>QVariant</type>
      <name>headerData</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a6500cff8e7312227347b971bd47e1190</anchor>
      <arglist>(int section, Qt::Orientation orientation, int role) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setData</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>aabe9da4a6f1e5027879ed7132aa03d01</anchor>
      <arglist>(const QModelIndex &amp;index, const QVariant &amp;value, int role=Qt::EditRole)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>append</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a940072d62162b130bfd0cec0c6fd4567</anchor>
      <arglist>(const Contributory &amp;contributory)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a00354b1b323c7d74d9cdef3333ef4df2</anchor>
      <arglist>(const int i)</arglist>
    </member>
    <member kind="function">
      <type>Qt::ItemFlags</type>
      <name>flags</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a7be83a445e2b0cc5b9751691ed33499b</anchor>
      <arglist>(const QModelIndex &amp;index) const </arglist>
    </member>
    <member kind="function">
      <type>QList&lt; Contributory &gt;</type>
      <name>getContributories</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>ae0aaacde6e79ccda128f589375f75e84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>count</name>
      <anchorfile>d4/d24/classContributoriesTableModel.html</anchorfile>
      <anchor>a9bc91f439c8b8320e64ef0531e8d5c62</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ContributoriesWidget</name>
    <filename>d0/d0b/classContributoriesWidget.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>add</name>
      <anchorfile>d0/d0b/classContributoriesWidget.html</anchorfile>
      <anchor>a58cdea8c2397c8bd1103e7a415f3e313</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d0/d0b/classContributoriesWidget.html</anchorfile>
      <anchor>a8203c0d2b23e658189dfd4b5ed9c8fbf</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>QList&lt; Contributory &gt;</type>
      <name>getContributories</name>
      <anchorfile>d0/d0b/classContributoriesWidget.html</anchorfile>
      <anchor>a2e6c4f02e6c5507ab0891867a6c2c3d8</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ContributoryDatabase</name>
    <filename>d6/d06/classContributoryDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>Models::Contributory *</type>
      <name>getContributory</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>a43d608f537112b55a920456f7b9e4a3b</anchor>
      <arglist>(const int idContributory)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addContributory</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>a9110546efa166d4d6c4703033328c368</anchor>
      <arglist>(const Models::Contributory &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateContributory</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>a5a202aded20ab3e90a89548203fddbb2</anchor>
      <arglist>(const Models::Contributory &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeContributory</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>afe934900e66553cb58e49ebf03a7d7a4</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>Models::Contributory *</type>
      <name>getContributory</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>a1c270940416109dca85ba246f5215142</anchor>
      <arglist>(QSqlQuery &amp;q)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ContributoryDatabase *</type>
      <name>instance</name>
      <anchorfile>d6/d06/classContributoryDatabase.html</anchorfile>
      <anchor>ac58610f75d4f51fa12c3e08cab1e4404</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerContextualMenu</name>
    <filename>d5/db9/classCustomerContextualMenu.html</filename>
    <member kind="function">
      <type></type>
      <name>CustomerContextualMenu</name>
      <anchorfile>d5/db9/classCustomerContextualMenu.html</anchorfile>
      <anchor>a798a08f4b8526398a54752e7de87930e</anchor>
      <arglist>(QWidget *w=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~CustomerContextualMenu</name>
      <anchorfile>d5/db9/classCustomerContextualMenu.html</anchorfile>
      <anchor>af3e43fde4d890830bfa33b948636faae</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerDatabase</name>
    <filename>dc/d7c/classCustomerDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getCustomersTable</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2e25b4f197ccbdd2c5753558dbe18d4b</anchor>
      <arglist>(QString filter=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getCustomersTree</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a0fc1ca7fe1020cef19b2423531c4e934</anchor>
      <arglist>(QString filter=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QSharedPointer&lt; Models::Customer &gt;</type>
      <name>getCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>ab6efaeabb32599dcccee6a94ee710402</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>aa46198ba7cf2ebb51161572e171e7e9c</anchor>
      <arglist>(const Models::Customer &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2e73d222f11beae089db0427a7c65f8e</anchor>
      <arglist>(const Models::Customer &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>aa1d21765bdf6319e580b3fcf20d841d1</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbCustomers</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a1c60ecbaa2594426b522746c70beee19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static CustomerDatabase *</type>
      <name>instance</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2b9546b1e5803c4055529d2a7f7df95e</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerDatabaseTest</name>
    <filename>d2/d63/classCustomerDatabaseTest.html</filename>
  </compound>
  <compound kind="class">
    <name>CustomerDataWidget</name>
    <filename>df/df4/classCustomerDataWidget.html</filename>
    <member kind="function">
      <type>void</type>
      <name>printUserData</name>
      <anchorfile>df/df4/classCustomerDataWidget.html</anchorfile>
      <anchor>a9a56bd1d7faf76d083cfa97f2883bdf1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printInformations</name>
      <anchorfile>df/df4/classCustomerDataWidget.html</anchorfile>
      <anchor>ab61052cc337e51d1e34149d67816c58f</anchor>
      <arglist>(int id)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerModelTest</name>
    <filename>d5/dcd/classCustomerModelTest.html</filename>
  </compound>
  <compound kind="class">
    <name>Database</name>
    <filename>de/d03/classDatabase.html</filename>
  </compound>
  <compound kind="class">
    <name>DbException</name>
    <filename>dd/dca/classDbException.html</filename>
    <member kind="function">
      <type></type>
      <name>DbException</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a22204317679895d999e3621cf97d5dee</anchor>
      <arglist>(const QString fct, const QString fctName, const QString logError, float errorCode)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~DbException</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a57b57d4d9010c06d158ccc44d45a1376</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>popupMessage</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a06765391cd11f596721c877c1a62c2f1</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DialogAddCustomer</name>
    <filename>df/d01/classDialogAddCustomer.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>checkFields</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>ac4e42b4dc828c57383fe3a9d04685f9c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DialogAddCustomer</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a6123adb32813c5ebe71ce06012c46b9c</anchor>
      <arglist>(int id=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>ae06c708abccad5ce0b8523c94b40eb75</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a1492352d114740bb44178f2415555155</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a6affc8db156ee183ffd14a71d06a8534</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ICheckField</name>
    <filename>d5/d75/classICheckField.html</filename>
  </compound>
  <compound kind="class">
    <name>ItemType</name>
    <filename>d2/de9/classItemType.html</filename>
    <member kind="function">
      <type></type>
      <name>ItemType</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>ae6db761c2f205fc9447d781015afb982</anchor>
      <arglist>(int type, QString name)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getName</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>a735cd1b13b8b4dc5c2d26793468f5516</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Models::IDatabaseModel *</type>
      <name>getModel</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>adf62a71c0e6766b8e93e809ec22876ce</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>a0ca95f11671b35aa0374b21f3ae4813a</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getType</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>ae6f722f3ddf0a38a6ffa5542b049d629</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setType</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>a90eda70d59c0321eec8d9397864adb77</anchor>
      <arglist>(int type)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>CUSTOMER</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>acb95d26d14359ec380296ca1d5a5cbdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>PROJECT</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>ad7a156ecb9641e198ddc95a7e648fb8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>BILLING</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>a4b72d61f3cdd0b89e59c51b3545c9312</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>QUOTE</name>
      <anchorfile>d2/de9/classItemType.html</anchorfile>
      <anchor>af058fe8d8650049f04ad37bbcbb058b8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Log</name>
    <filename>d0/d77/classLog.html</filename>
    <member kind="function">
      <type></type>
      <name>~Log</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>a0fbfda88fbee5027c89f6eb121059360</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>write</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>acef079f691840d7afd2ed9482d5d66ea</anchor>
      <arglist>(const QString text)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Log</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>af6071a60aa52b6c1b511f99b4bc1b8fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Log &amp;</type>
      <name>instance</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>ad8ef93302c147f832ed8202a6b039eb5</anchor>
      <arglist>(TypeLog type=INFO)</arglist>
    </member>
    <member kind="friend">
      <type>friend Log &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>a1ecba3328cadecbbd7d65ae2852171fc</anchor>
      <arglist>(Log &amp;logger, const QString &amp;text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MainWindow</name>
    <filename>d6/d1a/classMainWindow.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>addCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a661e495fc5b587dce8c7b930120098aa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>afff9ca5b1b867af6b54eb1c8d9501522</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>removeCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>adb6fcfe64c3a11f28655e397b3accea9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>addQuote</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>afd45bc05040ad2c44a35c020f687216d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editUser</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a32fb574dece506733a3b80d2ccf565ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>search</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a62fcad69e9d32b98f3ac40a5a1d0f398</anchor>
      <arglist>(QString s)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>search</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a274dd0e068ebdc2a752e7ef05209fb2d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>newProject</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a7093a481f61ac3dfd682245aaf4c03fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>removeProject</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>acac126b5b24ba9027f6a0052aec10baf</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editProject</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a9841d0d3f02715dbc3cfda9ad6b107ca</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutQt</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a4710d90108bd39f7b80bdc6c3a1b1aef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutFact</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a82e1b6ba63283af94f37684cf14b5c66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutFactDev</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>af9af9644d45d2af769d18f2370eed83e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutIcons</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>ae6a7598b9931ca8901a62bb95c490e0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>updateBtn</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>ac81b82b3eb71d75fcd72bd93da18112d</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MainWindow</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a8b244be8b7b7db1b08de2a2acb9409db</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getCurrentCustomerId</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a0584b17eb78c07b513524a09bd914042</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getCurrentProjectId</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a08d33fd0a3a0a46e39393fefcfc97a05</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCurrentCustomerName</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a11baa86aa3af94b94d9566523f1b95cb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCurrentProjectName</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a22db779c9d551c0c3adeb78a984ced8a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTreeRoot</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a9e01c4b4fb06ddff0aca86b4ffbb5743</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCustomerItemTree</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a9665f7564352d678a7886815d375a13a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isProjectItemTree</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>ae6f67694a02c0da2aca08c009ccb4b62</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MessageBox</name>
    <filename>d2/da3/classMessageBox.html</filename>
    <member kind="function">
      <type></type>
      <name>MessageBox</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a990d6667ca2831882090602c93169b0d</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aboutFact</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>ababd93e31998e3eabb1a655f044dea9c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aboutFactDev</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a18400f858bdb14e0af856893da73a932</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aboutIcons</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a9ffe14eb394b925e2a9a5a47c5f63238</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setImage</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a9b5ddfd71ace7cd38f383f5c011ce37a</anchor>
      <arglist>(QString img, int width=128, int height=128)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setText</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a98245b5ce8053833fe6b1f3900e85fe2</anchor>
      <arglist>(QString txt)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>showAboutFact</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>a8bd06bf00849e20b2a1f4cf0741eee6c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>showAboutFactDev</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>aea5966113f5e40d53b450691ce41071c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>showAboutIcons</name>
      <anchorfile>d2/da3/classMessageBox.html</anchorfile>
      <anchor>ac9212e2d9aaba9df3dfceb768486fc21</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Parameters</name>
    <filename>de/d0a/classParameters.html</filename>
    <member kind="function">
      <type></type>
      <name>Parameters</name>
      <anchorfile>de/d0a/classParameters.html</anchorfile>
      <anchor>af4d94ee360ac0157d9065f78797fe9a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const QString</type>
      <name>DB_FILENAME</name>
      <anchorfile>de/d0a/classParameters.html</anchorfile>
      <anchor>a80b98bd51d910bcc2203afcacbc7df87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const double</type>
      <name>VERSION</name>
      <anchorfile>de/d0a/classParameters.html</anchorfile>
      <anchor>a279ee24140c761de46178daa8960bdc8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Popup</name>
    <filename>d7/d6b/classPopup.html</filename>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>toImplement</name>
      <anchorfile>d7/d6b/classPopup.html</anchorfile>
      <anchor>aa3173e0f473b42f08363c4ef17c93a07</anchor>
      <arglist>(QString, QWidget *)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ProjectComboDelegate</name>
    <filename>d4/db0/classProjectComboDelegate.html</filename>
  </compound>
  <compound kind="class">
    <name>ProjectDatabase</name>
    <filename>d4/d8d/classProjectDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>Models::Project *</type>
      <name>getProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a1200663abcfc669e5eb68c4355d73405</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a0b35629c67cc0eb5d76823fd1ce9beaa</anchor>
      <arglist>(const Models::Project &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>ad57ce108679352e48b7138d6ee946326</anchor>
      <arglist>(const Models::Project &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a52f3c3b312c418568531eb4cd2ecf615</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbProjects</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a48ab28fa18bc3f0371f8c17c5421a46e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbProjectsForACustomer</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a3dbf2e270674727fc479d392c6609dec</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>QMap&lt; int, Models::Project &gt;</type>
      <name>getProjectsOfCustomer</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a5aaef2623cdab7bbad9a5dbd98f97566</anchor>
      <arglist>(QSharedPointer&lt; Models::Customer &gt; c)</arglist>
    </member>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getProjectsTable</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>af757914e88f67d9b62e4e762f8136048</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>Models::Project *</type>
      <name>getProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a8d3977e9b828772e4f2798598f94f984</anchor>
      <arglist>(QSqlQuery &amp;q)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ProjectDatabase *</type>
      <name>instance</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a06a93b599475687f19f66c7bbb921899</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ProjectsWidget</name>
    <filename>de/da7/classProjectsWidget.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>newProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a9a3e158093ed435a68d4d9874a22a128</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editSelectedProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a026e17f035717e382f4afca6896a72d3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>removeSelectedProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a038205ca1dee68dadae84e31dabfd7fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>addProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>ae745e92738053b6c3a514725fec9616f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>editProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a7be5b1aebb295169b201ceb4a7e3301a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="signal">
      <type>void</type>
      <name>removeProject</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a1ee6b31af551020de2aa560f18be0ccc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ProjectsWidget</name>
      <anchorfile>de/da7/classProjectsWidget.html</anchorfile>
      <anchor>a542fb678c61897b56c86dc58524bd969</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RateWidget</name>
    <filename>dc/da5/classRateWidget.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>setDailyRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>ae06885c9e58ed09e5a210a295bb3ffbb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>setHourlyRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>af7b6ceb4d9ceb8efe84a497c7a42d048</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RateWidget</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>ad1cb6a97e47b408043e83708ff8af15e</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>a4a3ec9a546055d6ecb3bd1a9ee8082a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWidgetDailyRateValue</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>ab96e6867dba808a1dc5b8c327a84f93e</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getDailyRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>a0a72cea5ff524b47e513dcb21aea2022</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getHourlyRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>a50285d4472979e004c706ff5640e8227</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setWidgetHourlyRateValue</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>a5f1061f95f2a45b88434fbdf99136030</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateConversionRate</name>
      <anchorfile>dc/da5/classRateWidget.html</anchorfile>
      <anchor>a04a7bd5b186482a60c16ed4334acd83b</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>searchTest</name>
    <filename>d7/d51/classsearchTest.html</filename>
  </compound>
  <compound kind="class">
    <name>searchWidget</name>
    <filename>d2/dfd/classsearchWidget.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>search</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>a15138eab0d8098a21c327bd34e328541</anchor>
      <arglist>(QString toSearch)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>getCustomerData</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>a09e08e9768fbb579c065bcff0d47c2ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>searchWidget</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>a0c712bf4f3c2105319645ce97e23eba9</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getCurrentCustomerId</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>ac74ae97eb8c147c89edc3dec3decf174</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCustomerSelected</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>ad69a78f1c657b026a149cdf61fd58f5e</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TestAdder</name>
    <filename>d0/d9b/classTestAdder.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>testadder</name>
    <filename>d7/d26/classtestadder.html</filename>
  </compound>
  <compound kind="class">
    <name>TestRunner</name>
    <filename>db/d70/classTestRunner.html</filename>
  </compound>
  <compound kind="class">
    <name>UserDatabase</name>
    <filename>de/d47/classUserDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getUserTable</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>a6020d6686916f20b3e6a1a5fa5fa7978</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Models::User *</type>
      <name>getUser</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>aa88164bd2cda084c86d77d73a3d820e1</anchor>
      <arglist>(const int pId=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateUser</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>a2d4981508ea96e6deb70d6bfd1360203</anchor>
      <arglist>(const Models::User &amp;)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static UserDatabase *</type>
      <name>instance</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>aa1ce356d9f6f903c786e5f623dac90b6</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>UserDataDialog</name>
    <filename>de/d9c/classUserDataDialog.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>checkFields</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a3ec2568b8b70aaf531585da0dc26f3de</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>UserDataDialog</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a51210d5e027d49b019fcd565d5b20e06</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a22f266169243757212ba7eb61d083ddb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>ad6ba344db1a10b804ca8f5f9a6ffed2c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a54519d6441212d50849de7b72ac5e623</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Utils</name>
    <filename>dc/dc5/classUtils.html</filename>
    <member kind="function" static="yes">
      <type>static QString</type>
      <name>firstLetterToUpper</name>
      <anchorfile>dc/dc5/classUtils.html</anchorfile>
      <anchor>a009b2a8ef00831aff87d2e46ca209398</anchor>
      <arglist>(QString s)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Models</name>
    <filename>dd/d20/namespaceModels.html</filename>
    <class kind="class">Models::Billing</class>
    <class kind="class">Models::Contributory</class>
    <class kind="class">Models::Customer</class>
    <class kind="class">Models::IDatabaseModel</class>
    <class kind="class">Models::Project</class>
    <class kind="class">Models::Search</class>
    <class kind="class">Models::User</class>
  </compound>
  <compound kind="class">
    <name>Models::Billing</name>
    <filename>d4/d5c/classModels_1_1Billing.html</filename>
    <base>Models::IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Billing</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ab6b6e4b21617bacb1e8124b5e1218723</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Billing</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a2fba091975b0c62f7e65771e335e038b</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Billing</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a36da0cd70a8f9db9be57bf32f7610e59</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ad2280a0d8dde4c36e88c344b01044caf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a689643008955fdcd5833631a6202c0dc</anchor>
      <arglist>(int getId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ada8a7c127a80fa7349fbd6a7d30ca4a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QMap&lt; Project *, QList&lt; Contributory &gt; &gt;</type>
      <name>getContributories</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a9c5e944c560fcecb356a9293b26f1ec6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addContributory</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a3636d785d2cb77d83d21a795e1f91a60</anchor>
      <arglist>(Contributory &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTitle</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a15cd358ce3cab05668c62c0771afdb85</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTitle</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ae20cea169abdffa5daaa368547425928</anchor>
      <arglist>(const QString &amp;getTitle)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a5802215da8f4407457b8aeb7be525c65</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>adb5cf4382150387f10bb6b774ace6bc8</anchor>
      <arglist>(const QString &amp;getDescription)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumber</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a48c6e28a4aec13f8ed6b3ebbab837f0b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNumber</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>a2b43e0c657a9e717c9d2c091d222369e</anchor>
      <arglist>(int getNumber)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBilling</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ab03dd29a9812a995355a1d93318f348f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIsBilling</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>aff8b71426c02bc97f0a724ef762cd42e</anchor>
      <arglist>(bool isBilling)</arglist>
    </member>
    <member kind="function">
      <type>QDate</type>
      <name>getDate</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>af0d1f0132d0902fb96456d0a9018b701</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDate</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ae8db0fe5fe273fad31e2f846b5b891cb</anchor>
      <arglist>(const QDate &amp;getDate)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>af3d8818a1e00eaa707058567fccf045b</anchor>
      <arglist>(const Billing &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>d4/d5c/classModels_1_1Billing.html</anchorfile>
      <anchor>ae6ff88e05384718d57be1be38f250a52</anchor>
      <arglist>(const Billing &amp;b)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IDatabaseModel</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a7dd56f574720919d1703651f5896141f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getId</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a6a4d1d3c0912c97c61a9d4de7471afee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setId</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a6bf2ec005b5d931e58ee8125e92d9722</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isToRemoved</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a058e5b85d95e9424245dc37eb122350c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setToRemoved</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>ac399b44ba1178ef6f54da31203e11d9f</anchor>
      <arglist>(bool toRemoved)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_id</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a85fbc8298dee2e84f310a21ed935665f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>_toRemoved</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>acfa9af965e01f44d6ff75226e23e4640</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::Contributory</name>
    <filename>d5/dd1/classModels_1_1Contributory.html</filename>
    <base>Models::IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Contributory</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a82c2a30e60a256099f25c424337d5aa0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Contributory</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>acbece77d876ca9d49d9fec868a74be5f</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Contributory</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a27d9ade910eab64b0e1135bb25ce0308</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a2d89036a02bd2828ff76d047338f61ba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a40248b5853045eb46412396513f36b06</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>ab9971d7867516b488095e63e1179eac8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Project *</type>
      <name>getProject</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a49379aeb4de2376d5a2aaf10f54daf05</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setProject</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a4478894daf317068856b707491d03555</anchor>
      <arglist>(Project *id)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getNbHours</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>ae85caa255441140fc1a3a0e91531bfc0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNbHours</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a1c7d65ee311232d3fd00cf8e4777f1c7</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>ae2b936f2fb1ccad2009eae9b5d12fc02</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>d5/dd1/classModels_1_1Contributory.html</anchorfile>
      <anchor>a12d4199fa7175c0b43f62eddf7c3d69e</anchor>
      <arglist>(const QString &amp;getDescription)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::Customer</name>
    <filename>db/dd7/classModels_1_1Customer.html</filename>
    <base>Models::IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Customer</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a28e8ade7d9ccc39707f823ba8d45f7d0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Customer</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a02a1aee507d4ff4f60019070793fe604</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>af5c0f2b6d80ad9e6bcbfe39b697d65c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>afe3ed7fb893d61ea6f4d14e73779382c</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a0f5dba0d90af0adf5d0aca26195d21b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFirstnameReferent</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a30934fb39c552863e588c40d01725a18</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFirstnameReferent</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a40cbc71c349a0d022b21543bbc7a120a</anchor>
      <arglist>(const QString &amp;firstnameReferent)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getLastnameReferent</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a73b93f9ad0718980bbfa2b283b3285ba</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLastnameReferent</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a64ff31bbe0c7aba0b9976d8d253b7b33</anchor>
      <arglist>(const QString &amp;lastnameReferent)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCompany</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a23fb516872c6aebf9b1eb6a7ec86cb7f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCompany</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ab4faf3a76242bc4c3ac44bafd628a4c6</anchor>
      <arglist>(const QString &amp;company)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getAddress</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a594e1458ca9f3a449f2628c861bc3a40</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAddress</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ae2d41b145d9c468f7e3c40a38882873d</anchor>
      <arglist>(const QString &amp;address)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPostalCode</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ad544bdcd4d021f92bd77e5aa24f31f21</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPostalCode</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a2bd4ac52294de78236e159caaa29412b</anchor>
      <arglist>(const QString &amp;postalCode)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCity</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ace3f86c1e5108ede84a1a09516b37e50</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCity</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a069b40292e037762ec5e5836682c50b0</anchor>
      <arglist>(const QString &amp;city)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCountry</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a70ecabd20451f2b7c24d22a931c94cc3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCountry</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>afd430475dc1bf7f9b1548767265aa821</anchor>
      <arglist>(const QString &amp;country)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getEmail</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ac8d55fcc6f53b2269a01efbe43e75133</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmail</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ab8f728a2e05c5c9c7a6f6522b85a59a1</anchor>
      <arglist>(const QString &amp;email)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getMobilePhone</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a97211324b1f890b5f7a3fffc447289d7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMobilePhone</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>abefe9de1e3c46501916e461ba6609450</anchor>
      <arglist>(const QString &amp;mobilePhone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPhone</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a0438cd11dfe13bb89c0233ffe288cc73</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPhone</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>abbc25028b09ae36da632cefbfbbbcce6</anchor>
      <arglist>(const QString &amp;phone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFax</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a08ce4fbbd62f3e3f407faea2bf351f69</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFax</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a4a6ba86c58db9bca2737bbeb723a0db3</anchor>
      <arglist>(const QString &amp;fax)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>ab379700fa93f5b9eb0f8546b03aff70f</anchor>
      <arglist>(const Customer &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>db/dd7/classModels_1_1Customer.html</anchorfile>
      <anchor>a07e61dd9ad79b6be765ea1dabccf1e18</anchor>
      <arglist>(const Customer &amp;c)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::IDatabaseModel</name>
    <filename>df/ddd/classModels_1_1IDatabaseModel.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>commit</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a8fcb1587824753cd121a7d961b60a98a</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>hydrat</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>af0814d81fc76a881bc64d9062adf1f6c</anchor>
      <arglist>(int id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>df/ddd/classModels_1_1IDatabaseModel.html</anchorfile>
      <anchor>a6d8eca5b493b57c21feafae75c783b14</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::Project</name>
    <filename>dd/d3f/classModels_1_1Project.html</filename>
    <base>Models::IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Project</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>acd757cadcbeda1f4f83a2b0cd3c1cec1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Project</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a408d5fb64bb72b9492778b2ae26331f2</anchor>
      <arglist>(QString name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Project</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ac6c56b6ff24598135bc54d3b3edd3a47</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Project</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a938f33016740cf7b33984d92ed932991</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>afc167f2b5bf9c354826117c5057628ae</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>aa293709eeb68e4271cac8d4cce418ffa</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ab55c71c009ae796e7dbe03017fed67ee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getName</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a11d3b85bdc38daba928bfbfd962a0e32</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ac5ffa6ff6d31647fd880881257f47889</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a065b9cd68962c78302a84c686e10ae13</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a2cccaca77bff95f13b3320f3f03dc9e7</anchor>
      <arglist>(const QString &amp;description)</arglist>
    </member>
    <member kind="function">
      <type>QDate</type>
      <name>getBeginDate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a31b8e46aabb1327499f7e36f170900e3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBeginDate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a07dfb00cbec7442197a91bc0795ab14d</anchor>
      <arglist>(QDate beginDate)</arglist>
    </member>
    <member kind="function">
      <type>QDate</type>
      <name>getEndDate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ae925d3750ebce7b1b30c9dc7c08302b0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEndDate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a89e9603b862d0a282e4eb03e122e8c05</anchor>
      <arglist>(QDate endDate)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getDailyRate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a46d74a7452e712d223f1ca444a4cc180</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDailyRate</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a9bc03d9632334a550bd25f6286d2c7a2</anchor>
      <arglist>(double dailyRate)</arglist>
    </member>
    <member kind="function">
      <type>QSharedPointer&lt; Customer &gt;</type>
      <name>getCustomer</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ad15f442a24c9d42144b73f27a7afaa35</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCustomer</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a9d305edf054735b911e144516d3eccba</anchor>
      <arglist>(QSharedPointer&lt; Customer &gt; customer)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const double</type>
      <name>LEGAL_RATE</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>ad3dc764849815160de77877b1e261c86</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int</type>
      <name>NB_DAILY_HOURS</name>
      <anchorfile>dd/d3f/classModels_1_1Project.html</anchorfile>
      <anchor>a2cde659bf6be8b4919d7b4b7a53c336f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::Search</name>
    <filename>d6/d44/classModels_1_1Search.html</filename>
    <member kind="function">
      <type></type>
      <name>Search</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a05ea0037161dce5dde6876afa384d71f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Search</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a6b51a9a47bfc35addb8204ff89afefe3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFilter</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>ab3ec88b48f6b404f8027dcbfce1495c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getSearchInCompanies</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>ad38428f4aa81ba5951f82e0fcb92779c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSearchInCompanies</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>ac32bf6038d77b99a097faee3efa04cc7</anchor>
      <arglist>(bool getSearchInCompanies)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getSearchInReferentLastname</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>aa415bcd966fef7bcd1cd5bd3373d57f6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSearchInReferentLastname</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>adf5e7ebfc61b309db1b110de5167b6d5</anchor>
      <arglist>(bool getSearchInReferentLastname)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getGroupFilter</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a2f5ee925709a654cedef85732e448438</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGroupFilter</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a5feb06679973719e31007e659c08cc06</anchor>
      <arglist>(bool getGroupFilter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getText</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a30d4355f72278e6e466dc64208947f8b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setText</name>
      <anchorfile>d6/d44/classModels_1_1Search.html</anchorfile>
      <anchor>a1bd00e3da5d5e10b4bec6579fb1c8bfa</anchor>
      <arglist>(const QString &amp;getText)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Models::User</name>
    <filename>df/d68/classModels_1_1User.html</filename>
    <base>Models::IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>User</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ab106b51be814f7d3a055874781f1f2ee</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>User</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a8eb50ce05c34b28cf39ff980066f3113</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ada0daaa6886be3716af6e15d28c01915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ab46c7e1841dca66bc01cd95328b97877</anchor>
      <arglist>(int id=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ae0870269116b5bda3b5f1c8527e300be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFirstname</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a409a0a6becdd16b9a34120511526ab4d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFirstname</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a9fdff0463dc3653dd3c3bb7b60bf6c98</anchor>
      <arglist>(const QString &amp;firstname)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getLastname</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>acd71c39455f4289dac70fe3688b956a6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLastname</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a3537478a5fe9e2bcb74cd7e267ca1a5f</anchor>
      <arglist>(const QString &amp;lastname)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCompany</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a5c2a1436bfaaf39df26d1ff45196ff43</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCompany</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ab51a6e7ea016ad3c7d18c754582edd53</anchor>
      <arglist>(const QString &amp;company)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTitle</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a56a37a1b1125c28e8e72c9a3551b7da5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTitle</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a0fe65ebdee17c2986c874e480e1cb0bd</anchor>
      <arglist>(const QString &amp;title)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getAddress</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>afef76dde9b2e3fdb3c2fef33c2dc0d4d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAddress</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a2a6098ed13472398a972944b88905ebd</anchor>
      <arglist>(const QString &amp;address)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPostalCode</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a4d6dae7e681b0acc7bbd1c4cc7b84062</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPostalCode</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a5a75307bb95eae0970efd282519ec5ba</anchor>
      <arglist>(const QString &amp;postalCode)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCity</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a6ee95d68097373de6273bd0386f2dff1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCity</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a98c035e4275b8170bec888bea05b24d9</anchor>
      <arglist>(const QString &amp;city)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getEmail</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a90b1f27762a58bbe2e903d8299678b74</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmail</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a69fc70b244bccf493df300af812a18c3</anchor>
      <arglist>(const QString &amp;email)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getMobilePhone</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>aba9d318cad6935104eff02f6b5659d5c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMobilePhone</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>abed6684c24a3ba695a90a69a3a6d7572</anchor>
      <arglist>(const QString &amp;mobilePhone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPhone</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>adc8fbd6d75a41d9ac9ee9473d781d1c1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPhone</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>adb132ecafc7cc0afd42fc260f8a2e7b9</anchor>
      <arglist>(const QString &amp;phone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getNoSiret</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>a617ee9ede3791842fbf8593f08660d37</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNoSiret</name>
      <anchorfile>df/d68/classModels_1_1User.html</anchorfile>
      <anchor>ae751ee06859dffce0cad08005c42c933</anchor>
      <arglist>(const QString &amp;noSiret)</arglist>
    </member>
  </compound>
  <compound kind="dir">
    <name>src/widgets/checkfields</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/widgets/checkfields/</path>
    <filename>dir_85da786ff65cbda030d304d3a1e6a30e.html</filename>
    <file>checkcity.cpp</file>
    <file>checkcity.h</file>
    <file>checkcountry.cpp</file>
    <file>checkcountry.h</file>
    <file>checkemail.cpp</file>
    <file>checkemail.h</file>
    <file>checkfieldsletters.cpp</file>
    <file>checkfieldsletters.h</file>
    <file>checkname.cpp</file>
    <file>checkname.h</file>
    <file>checkphone.cpp</file>
    <file>checkphone.h</file>
    <file>checkpostalcode.cpp</file>
    <file>checkpostalcode.h</file>
    <file>checkqlineedit.cpp</file>
    <file>checkqlineedit.h</file>
    <file>checksiretnumber.cpp</file>
    <file>checksiretnumber.h</file>
    <file>checkuntilfield.cpp</file>
    <file>checkuntilfield.h</file>
    <file>checkvalidfield.cpp</file>
    <file>checkvalidfield.h</file>
    <file>icheckfield.h</file>
  </compound>
  <compound kind="dir">
    <name>tests/database</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/tests/database/</path>
    <filename>dir_75d760846aa40227f00e44530a510c90.html</filename>
    <file>billingdatabasetest.cpp</file>
    <file>billingdatabasetest.h</file>
    <file>contributoriesdatabasetest.cpp</file>
    <file>contributoriesdatabasetest.h</file>
    <file>customerdatabasetest.cpp</file>
    <file>customerdatabasetest.h</file>
  </compound>
  <compound kind="dir">
    <name>src/database</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/database/</path>
    <filename>dir_803ee67260c130b45d29089798491ab2.html</filename>
    <file>billingdatabase.cpp</file>
    <file>billingdatabase.h</file>
    <file>contributorydatabase.cpp</file>
    <file>contributorydatabase.h</file>
    <file>customerdatabase.cpp</file>
    <file>customerdatabase.h</file>
    <file>database.cpp</file>
    <file>database.h</file>
    <file>projectdatabase.cpp</file>
    <file>projectdatabase.h</file>
    <file>userdatabase.cpp</file>
    <file>userdatabase.h</file>
  </compound>
  <compound kind="dir">
    <name>src/widgets/delegates</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/widgets/delegates/</path>
    <filename>dir_b468fe03d98886b78ec49523fac59f95.html</filename>
    <file>projectcombodelegate.cpp</file>
    <file>projectcombodelegate.h</file>
  </compound>
  <compound kind="dir">
    <name>src/dialogs</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/dialogs/</path>
    <filename>dir_9870864803860a03def48f6710b1f137.html</filename>
    <dir>src/dialogs/messagebox</dir>
    <file>addcontributorydialog.cpp</file>
    <file>addcontributorydialog.h</file>
    <file>addprojectdialog.cpp</file>
    <file>addprojectdialog.h</file>
    <file>addquotedialog.cpp</file>
    <file>addquotedialog.h</file>
    <file>dialogaddcustomer.cpp</file>
    <file>dialogaddcustomer.h</file>
    <file>userdatadialog.cpp</file>
    <file>userdatadialog.h</file>
  </compound>
  <compound kind="dir">
    <name>src/exceptions</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/exceptions/</path>
    <filename>dir_6e33d6500a76933db4361f663e54ab12.html</filename>
    <file>dbexception.cpp</file>
    <file>dbexception.h</file>
  </compound>
  <compound kind="dir">
    <name>src/dialogs/messagebox</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/dialogs/messagebox/</path>
    <filename>dir_2ba520ac699545e0dbf222843725d59b.html</filename>
    <file>messagebox.cpp</file>
    <file>messagebox.h</file>
    <file>messageboxhelp.cpp</file>
  </compound>
  <compound kind="dir">
    <name>tests/models</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/tests/models/</path>
    <filename>dir_c7ec7d3a96f76aec1e8b71e782fe5cbb.html</filename>
    <file>billingmodeltest.cpp</file>
    <file>billingmodeltest.h</file>
    <file>customermodeltest.cpp</file>
    <file>customermodeltest.h</file>
    <file>searchtest.cpp</file>
    <file>searchtest.h</file>
  </compound>
  <compound kind="dir">
    <name>src/models</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/models/</path>
    <filename>dir_bdeba5f06b852fec80257c0bf4c3c36e.html</filename>
    <file>billing.cpp</file>
    <file>billing.h</file>
    <file>contributory.cpp</file>
    <file>contributory.h</file>
    <file>customer.cpp</file>
    <file>customer.h</file>
    <file>idatabasemodel.h</file>
    <file>project.cpp</file>
    <file>project.h</file>
    <file>search.cpp</file>
    <file>search.h</file>
    <file>user.cpp</file>
    <file>user.h</file>
  </compound>
  <compound kind="dir">
    <name>tests/QTestRunner</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/tests/QTestRunner/</path>
    <filename>dir_2c44b78b8b65d06e29d47a71b2001f3a.html</filename>
    <file>main.cpp</file>
    <file>testadder.cpp</file>
    <file>testadder.h</file>
    <file>testrunner.cpp</file>
    <file>testrunner.h</file>
  </compound>
  <compound kind="dir">
    <name>src</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/</path>
    <filename>dir_68267d1309a1af8e8297ef4c3efbcdba.html</filename>
    <dir>src/database</dir>
    <dir>src/dialogs</dir>
    <dir>src/exceptions</dir>
    <dir>src/models</dir>
    <dir>src/widgets</dir>
    <file>itemtype.cpp</file>
    <file>itemtype.h</file>
    <file>log.cpp</file>
    <file>log.h</file>
    <file>mainwindow.cpp</file>
    <file>mainwindow.h</file>
    <file>parameters.cpp</file>
    <file>parameters.h</file>
    <file>utils.cpp</file>
    <file>utils.h</file>
  </compound>
  <compound kind="dir">
    <name>tests</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/tests/</path>
    <filename>dir_59425e443f801f1f2fd8bbe4959a3ccf.html</filename>
    <dir>tests/database</dir>
    <dir>tests/models</dir>
    <dir>tests/QTestRunner</dir>
    <file>main.cpp</file>
  </compound>
  <compound kind="dir">
    <name>src/widgets</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/widgets/</path>
    <filename>dir_0abdee562046be6f5823d1ca8c3fd13c.html</filename>
    <dir>src/widgets/checkfields</dir>
    <dir>src/widgets/delegates</dir>
    <dir>src/widgets/widgetsmodels</dir>
    <file>comboboxmodelwidget.cpp</file>
    <file>comboboxmodelwidget.h</file>
    <file>contributorieswidget.cpp</file>
    <file>contributorieswidget.h</file>
    <file>customercontextualmenu.cpp</file>
    <file>customercontextualmenu.h</file>
    <file>customerdatawidget.cpp</file>
    <file>customerdatawidget.h</file>
    <file>popup.cpp</file>
    <file>popup.h</file>
    <file>projectswidget.cpp</file>
    <file>projectswidget.h</file>
    <file>ratewidget.cpp</file>
    <file>ratewidget.h</file>
    <file>searchwidget.cpp</file>
    <file>searchwidget.h</file>
  </compound>
  <compound kind="dir">
    <name>src/widgets/widgetsmodels</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/widgets/widgetsmodels/</path>
    <filename>dir_bd05c1a27c2a43e11919786bc921e584.html</filename>
    <file>contributoriestablemodel.cpp</file>
    <file>contributoriestablemodel.h</file>
  </compound>
  <compound kind="page">
    <name>index</name>
    <title>FactDev documentation</title>
    <filename>index</filename>
  </compound>
</tagfile>
