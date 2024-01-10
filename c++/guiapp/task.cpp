#include "task.h"
#include "./ui_task.h"
#include <QInputDialog>
#include <QFont>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::rename);

    connect(ui->removeButton, &QPushButton::clicked,
            [this] {
                    emit removed(this);
                   });

    connect(ui->checkbox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

/* Set name on UI 'checkbox' named element
 * to string given
 */
void Task::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

QString Task::name() const
{
    return ui->checkbox->text();
}
// Return whether or not 'checkbox' UI element is checked
bool Task::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(), &ok);
    if (ok && !value.isEmpty()) {
        setName(value);
    }
}

void Task::checked(bool checked)
{
    // Create copy of current font styel
    QFont font(ui->checkbox->font());
    // Strike it out
    font.setStrikeOut(checked);
    // Set it
    ui->checkbox->setFont(font);
    // Emit signal
    emit statusChanged(this);
}
