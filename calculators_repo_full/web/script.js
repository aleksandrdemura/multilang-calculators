document.getElementById('calc').addEventListener('click', () => {
  const a = parseFloat(document.getElementById('a').value);
  const b = parseFloat(document.getElementById('b').value);
  const op = document.getElementById('op').value;
  const res = document.getElementById('res');
  if (Number.isNaN(a) || Number.isNaN(b)) { res.textContent = 'Результат: Ошибка ввода'; return; }
  if (op === '/' && b === 0) { res.textContent = 'Результат: Деление на ноль'; return; }
  let r;
  if (op === '+') r = a + b;
  if (op === '-') r = a - b;
  if (op === '*') r = a * b;
  if (op === '/') r = a / b;
  res.textContent = 'Результат: ' + r;
});
document.getElementById('clear').addEventListener('click', () => {
  document.getElementById('a').value = '';
  document.getElementById('b').value = '';
  document.getElementById('res').textContent = 'Результат: —';
});
