"use strict";
var framework;
(function (framework) {
    var FileParser = /** @class */ (function () {
        function FileParser(filename, content) {
            this.filename = filename;
            this.content = [];
            for (var _i = 0, _a = content.trim().split('\n'); _i < _a.length; _i++) {
                var line = _a[_i];
                var words = line.trim().split(new RegExp('\\s+'));
                this.content.push(words);
            }
            this.y = 0;
            this.x = 0;
        }
        FileParser.prototype.isEOF = function () {
            return this.content.length <= this.y;
        };
        FileParser.prototype.getWord = function () {
            if (this.isEOF()) {
                this.reportError('a word expected, but EOF');
            }
            if (this.content[this.y].length <= this.x) {
                this.reportError('a word expected, but newline');
            }
            var word = this.content[this.y][this.x];
            this.x += 1;
            return word;
        };
        FileParser.prototype.getInt = function () {
            var word = this.getWord();
            if (!word.match(new RegExp('^[-+]?[0-9]+$'))) {
                this.reportError("a number expected, but word " + JSON.stringify(this.content[this.y][this.x]));
            }
            return parseInt(word);
        };
        FileParser.prototype.getNewline = function () {
            if (this.isEOF()) {
                this.reportError('newline expected, but EOF');
            }
            if (this.x < this.content[this.y].length) {
                this.reportError("newline expected, but word " + JSON.stringify(this.content[this.y][this.x]));
            }
            this.x = 0;
            this.y += 1;
        };
        FileParser.prototype.reportError = function (msg) {
            msg = this.filename + ": line " + (this.y + 1) + ": " + msg;
            alert(msg);
            throw new Error(msg);
        };
        return FileParser;
    }());
    framework.FileParser = FileParser;
    var FileSelector = /** @class */ (function () {
        function FileSelector(callback) {
            var _this = this;
            this.callback = callback;
            this.inputFile = document.getElementById("inputFile");
            this.outputFile = document.getElementById("outputFile");
            this.reloadButton = document.getElementById("reloadButton");
            this.reloadFilesClosure = function () {
                _this.reloadFiles();
            };
            this.inputFile.addEventListener('change', this.reloadFilesClosure);
            this.outputFile.addEventListener('change', this.reloadFilesClosure);
            this.reloadButton.addEventListener('click', this.reloadFilesClosure);
        }
        FileSelector.prototype.reloadFiles = function () {
            var _this = this;
            if (this.inputFile.files == null || this.inputFile.files.length == 0)
                return;
            loadFile(this.inputFile.files[0], function (inputContent) {
                if (_this.outputFile.files == null || _this.outputFile.files.length == 0)
                    return;
                loadFile(_this.outputFile.files[0], function (outputContent) {
                    _this.reloadButton.classList.remove('disabled');
                    if (_this.callback !== undefined) {
                        _this.callback(inputContent, outputContent);
                    }
                });
            });
        };
        return FileSelector;
    }());
    framework.FileSelector = FileSelector;
    var RichSeekBar = /** @class */ (function () {
        function RichSeekBar(callback) {
            var _this = this;
            this.callback = callback;
            this.seekRange = document.getElementById("seekRange");
            this.seekNumber = document.getElementById("seekNumber");
            this.fpsInput = document.getElementById("fpsInput");
            this.firstButton = document.getElementById("firstButton");
            this.prevButton = document.getElementById("prevButton");
            this.playButton = document.getElementById("playButton");
            this.nextButton = document.getElementById("nextButton");
            this.lastButton = document.getElementById("lastButton");
            this.runIcon = document.getElementById("runIcon");
            this.intervalId = null;
            this.setMinMax(-1, -1);
            this.seekRange.addEventListener('change', function () {
                _this.setValue(parseInt(_this.seekRange.value));
            });
            this.seekNumber.addEventListener('change', function () {
                _this.setValue(parseInt(_this.seekNumber.value));
            });
            this.seekRange.addEventListener('input', function () {
                _this.setValue(parseInt(_this.seekRange.value));
            });
            this.seekNumber.addEventListener('input', function () {
                _this.setValue(parseInt(_this.seekNumber.value));
            });
            this.fpsInput.addEventListener('change', function () {
                if (_this.intervalId !== null) {
                    _this.play();
                }
            });
            this.firstButton.addEventListener('click', function () {
                _this.stop();
                _this.setValue(_this.getMin());
            });
            this.prevButton.addEventListener('click', function () {
                _this.stop();
                _this.setValue(_this.getValue() - 1);
            });
            this.nextButton.addEventListener('click', function () {
                _this.stop();
                _this.setValue(_this.getValue() + 1);
            });
            this.lastButton.addEventListener('click', function () {
                _this.stop();
                _this.setValue(_this.getMax());
            });
            this.playClosure = function () {
                _this.play();
            };
            this.stopClosure = function () {
                _this.stop();
            };
            this.playButton.addEventListener('click', this.playClosure);
        }
        RichSeekBar.prototype.setMinMax = function (min, max) {
            this.seekRange.min = this.seekNumber.min = min.toString();
            this.seekRange.max = this.seekNumber.max = max.toString();
            this.seekRange.step = this.seekNumber.step = '1';
            this.setValue(min);
        };
        RichSeekBar.prototype.getMin = function () {
            return parseInt(this.seekRange.min);
        };
        RichSeekBar.prototype.getMax = function () {
            return parseInt(this.seekRange.max);
        };
        RichSeekBar.prototype.setValue = function (value) {
            value = Math.max(this.getMin(), Math.min(this.getMax(), value)); // clamp
            var preValue = this.seekNumber.valueAsNumber;
            this.seekRange.value = this.seekNumber.value = value.toString();
            if (this.callback !== undefined) {
                this.callback(value, preValue);
            }
        };
        RichSeekBar.prototype.getValue = function () {
            return parseInt(this.seekRange.value);
        };
        RichSeekBar.prototype.getDelay = function () {
            var fps = parseInt(this.fpsInput.value);
            return Math.floor(1000 / fps);
        };
        RichSeekBar.prototype.resetInterval = function () {
            if (this.intervalId) {
                clearInterval(this.intervalId);
                this.intervalId = null;
            }
        };
        RichSeekBar.prototype.play = function () {
            var _this = this;
            this.playButton.removeEventListener('click', this.playClosure);
            this.playButton.addEventListener('click', this.stopClosure);
            this.runIcon.classList.remove('play');
            this.runIcon.classList.add('stop');
            if (this.getValue() == this.getMax()) { // if last, go to first
                this.setValue(this.getMin());
            }
            this.resetInterval();
            this.intervalId = setInterval(function () {
                if (_this.getValue() == _this.getMax()) {
                    _this.stop();
                }
                else {
                    _this.setValue(_this.getValue() + 1);
                }
            }, this.getDelay());
        };
        RichSeekBar.prototype.stop = function () {
            this.playButton.removeEventListener('click', this.stopClosure);
            this.playButton.addEventListener('click', this.playClosure);
            this.runIcon.classList.remove('stop');
            this.runIcon.classList.add('play');
            this.resetInterval();
        };
        return RichSeekBar;
    }());
    framework.RichSeekBar = RichSeekBar;
    var loadFile = function (file, callback) {
        var reader = new FileReader();
        reader.readAsText(file);
        reader.onloadend = function () {
            if (typeof reader.result == 'string')
                callback(reader.result);
        };
    };
    var saveUrlAsLocalFile = function (url, filename) {
        var anchor = document.createElement('a');
        anchor.href = url;
        anchor.download = filename;
        var evt = document.createEvent('MouseEvent');
        evt.initEvent("click", true, true);
        anchor.dispatchEvent(evt);
    };
    var FileExporter = /** @class */ (function () {
        function FileExporter(canvas) {
            var saveAsImage = document.getElementById("saveAsImage");
            saveAsImage.addEventListener('click', function () {
                saveUrlAsLocalFile(canvas.toDataURL('image/png'), 'canvas.png');
            });
        }
        return FileExporter;
    }());
    framework.FileExporter = FileExporter;
})(framework || (framework = {}));
var visualizer;
(function (visualizer) {
    var InputFile = /** @class */ (function () {
        function InputFile(content) {
            this.cells = [];
            var parser = new framework.FileParser('<input-file>', content);
            this.N = parser.getInt();
            this.M = parser.getInt();
            this.K = parser.getInt();
            this.A = [];
            parser.getNewline();
            for (var i = 0; i < this.N; i++) {
                var a = parser.getInt();
                if (a <= 0 || a >= this.K)
                    parser.reportError("value " + a + " is out of range");
                this.A.push(a);
            }
        }
        return InputFile;
    }());
    var OutputFile = /** @class */ (function () {
        function OutputFile(content, inputFile) {
            this.commands = [];
            var N = inputFile.N;
            var M = inputFile.M;
            var parser = new framework.FileParser('<output-file>', content.trim());
            for (var i = 0; i < M; i++) {
                var p = parser.getInt();
                var q = parser.getInt();
                if (p < 0 || p >= N)
                    parser.reportError("index " + p + " is out of range");
                if (q < 0 || q >= N)
                    parser.reportError("index " + q + " is out of range");
                this.commands.push([p, q]);
                parser.getNewline();
                if (parser.isEOF())
                    break
                else if (i == M - 1)
                    parser.reportError("Too long file.");
            }
        }
        return OutputFile;
    }());
    var TesterFrame = /** @class */ (function () {
        function TesterFrame(turn, input, output, previousFrame, command, A) {
            this.turn = turn;
            this.input = input;
            this.output = output;
            this.previousFrame = previousFrame;
            this.command = command;
            this.A = A;
            this.score = calcScore(input.N, input.M, input.K, A, turn)
        }
        TesterFrame.createInitialFrame = function (input, output) {
            return new TesterFrame(0, input, output, null, null, input.A);
        };
        TesterFrame.createNextFrame = function (previousFrame, command) {
            var A = previousFrame.A.slice();
            var p = command[0];
            var q = command[1];
            A[p] = (A[p] + A[q]) % previousFrame.input.K;
            return new TesterFrame(previousFrame.turn + 1, previousFrame.input, previousFrame.output, previousFrame, command, A);
        };
        return TesterFrame;
    }());
    function calcScore(N, M, K, A, turn) {
        var score = 0.0;
        var zeroCnt = 0;
        for (var i = 0; i < N; i++) {
            if (A[i] === 0) zeroCnt++;
            score += Math.log2(K) - Math.log2(A[i] + 1);
        }
        score = Math.ceil(score);
        if (zeroCnt >= N - 1) score += M - turn;
        return score;
    }
    var Tester = /** @class */ (function () {
        function Tester(inputContent, outputContent) {
            var input = new InputFile(inputContent);
            var output = new OutputFile(outputContent, input);
            this.frames = [TesterFrame.createInitialFrame(input, output)];
            for (var _i = 0, _a = output.commands; _i < _a.length; _i++) {
                var command = _a[_i];
                var lastFrame = this.frames[this.frames.length - 1];
                this.frames.push(TesterFrame.createNextFrame(lastFrame, command));
            }
        }
        return Tester;
    }());
    var Visualizer = /** @class */ (function () {
        function Visualizer() {
            this.barColor = "#111";
            this.barColorP = "#E11";
            this.barColorQ = "#11E";
            this.barMargin = 1;
            this.bgColor = '#EEE';
            this.canvas = document.getElementById("canvas");
            // デバイスの解像度に合わせてcanvasの解像度を調整
            this.dpr = window.devicePixelRatio || 1;
            this.lineDash = [5, 5];
            this.lineStyle = "#444";
            var height = this.canvas.height;
            var width = this.canvas.width;
            // 表示上のcanvasはサイズを変更しない（dpr倍緻密に描画される）
            this.canvas.style.height = height + 'px';
            this.canvas.style.width = width + 'px';
            // 実際のcanvasのサイズはdpr倍にする
            this.height = this.canvas.height = height * this.dpr; // pixels
            this.width = this.canvas.width = width * this.dpr; // pixels
            this.ctx = this.canvas.getContext('2d');
            if (this.ctx == null) {
                alert('unsupported browser');
            }
            this.commandInput = document.getElementById("commandInput");
            this.diffInput = document.getElementById("diffInput");
            this.scoreInput = document.getElementById("scoreInput");
            this.showLogCheck = document.getElementById("showLogCheck");
            // canvas左下を基準点にする（ただし文字等は反転するので描画前にscale(1, -1)が必要）
            this.ctx.translate(0, this.height);
            this.ctx.scale(1, -1);
        }
        Visualizer.prototype.draw = function (frame, prev) {
            this.commandInput.value = frame.command ? frame.command.join(" ") : "";
            this.diffInput.value = this.diffText(frame, frame.previousFrame)
            this.scoreInput.value = frame.score.toString();
            var barHeight = this.height;
            var barWidth = this.width / frame.input.N - this.barMargin;
            if (prev) {
                this.drawPartial(frame, prev, barHeight, barWidth);
            }
            else {
                this.drawAll(frame, barHeight, barWidth);
            }
            this.drawLines();
        };
        Visualizer.prototype.drawPartial = function (frame, prev, barHeight, barWidth) {
            if (frame.command == null)
                return;
            {
                var c = prev.command;
                if (c != null) {
                    var p = c[0];
                    this.eraseBar(p, barHeight, barWidth);
                    this.drawBar(p, frame.A[p], frame.input.K, barHeight, barWidth, this.barColor);
                    var q = c[1];
                    this.eraseBar(q, barHeight, barWidth);
                    this.drawBar(q, frame.A[q], frame.input.K, barHeight, barWidth, this.barColor);
                }
            }
            {
                var c = frame.command;
                if (c != null) {
                    var p = c[0];
                    this.eraseBar(p, barHeight, barWidth);
                    this.drawBar(p, frame.A[p], frame.input.K, barHeight, barWidth, this.barColorP);
                    var q = c[1];
                    if (p !== q) {
                        this.eraseBar(q, barHeight, barWidth);
                        this.drawBar(q, frame.A[q], frame.input.K, barHeight, barWidth, this.barColorQ);
                    }
                }
            }
        };
        Visualizer.prototype.drawAll = function (frame, barHeight, barWidth) {
            this.ctx.fillStyle = this.bgColor;
            this.ctx.fillRect(0, 0, this.width, this.height);
            var N = frame.input.N;
            for (var i = 0; i < N; i++) {
                this.drawBar(i, frame.A[i], frame.input.K, barHeight, barWidth, this.barColor);
            }
            if (frame.command != null) {
                var c = frame.command;
                var p = c[0];
                this.eraseBar(p, barHeight, barWidth);
                this.drawBar(p, frame.A[p], frame.input.K, barHeight, barWidth, this.barColorP);
                var q = c[1];
                this.eraseBar(q, barHeight, barWidth);
                this.drawBar(q, frame.A[q], frame.input.K, barHeight, barWidth, this.barColorQ);
            }
        };
        Visualizer.prototype.drawBar = function (i, a, k, barHeight, barWidth, color) {
            var showLog = this.showLogCheck.checked;
            var height = barHeight * (showLog ? Math.log(a + 1) / Math.log(k + 1) : a / k);
            this.ctx.save();
            this.ctx.fillStyle = color;
            this.ctx.fillRect(i * (barWidth + this.barMargin), 0, barWidth, height);
            this.ctx.restore();
        };
        Visualizer.prototype.eraseBar = function (i, barHeight, barWidth) {
            this.ctx.save();
            this.ctx.fillStyle = this.bgColor;
            this.ctx.fillRect(i * (barWidth + this.barMargin), 0, barWidth, barHeight);
            this.ctx.restore();
        };
        Visualizer.prototype.diffText = function (frame, prev) {
            var command = frame.command;
            if (command == null) return "";
            var p = command[0], q = command[1];
            var A = frame.A, Aprev = prev.A;
            return `${Aprev[p]} -> ${A[p]} (+${Aprev[q]})`;
        };
        Visualizer.prototype.drawLines = function () {
            this.ctx.save();
            this.ctx.setLineDash(this.lineDash);
            for (var style of [this.bgColor, this.lineStyle]) {
                this.ctx.strokeStyle = style;
                this.ctx.beginPath();
                for (var i = 1; i < 4; i++) {
                    var y = this.height * i / 4;
                    this.ctx.moveTo(0, y);
                    this.ctx.lineTo(this.width, y);
                }
                this.ctx.stroke();
            }
            this.ctx.restore();
        };
        Visualizer.prototype.getCanvas = function () {
            return this.canvas;
        };
        return Visualizer;
    }());
    var App = /** @class */ (function () {
        function App() {
            var _this = this;
            this.tester = null;
            this.visualizer = new Visualizer();
            this.exporter = new framework.FileExporter(this.visualizer.getCanvas());
            this.seek = new framework.RichSeekBar(function (curValue, preValue) {
                if (_this.tester) {
                    if (preValue == curValue - 1) {
                        _this.visualizer.draw(_this.tester.frames[curValue], _this.tester.frames[preValue]);
                    }
                    else {
                        _this.visualizer.draw(_this.tester.frames[curValue], null);
                    }
                }
            });
            this.loader = new framework.FileSelector(function (inputContent, outputContent) {
                _this.tester = new Tester(inputContent, outputContent);
                _this.seek.setMinMax(0, _this.tester.frames.length - 1);
                _this.seek.setValue(_this.tester.frames.length - 1);
                _this.visualizer.draw(_this.tester.frames[_this.tester.frames.length - 1], null);
            });
            this.visualizer.showLogCheck.addEventListener('change', function () {
                if (_this.tester !== undefined) {
                    _this.visualizer.draw(_this.tester.frames[_this.seek.getValue()]);
                }
            });
        }
        return App;
    }());
    visualizer.App = App;
})(visualizer || (visualizer = {}));
window.onload = function () {
    new visualizer.App();
};
